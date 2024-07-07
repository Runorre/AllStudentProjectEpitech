##
## EPITECH PROJECT, 2024
## zappy
## File description:
## ai
##

from __future__ import annotations
from base64 import b64decode, b64encode
from contextlib import suppress
from os import path
from socket import AF_INET, SOCK_STREAM, socket, timeout
from subprocess import Popen
from typing import Literal, NoReturn, Optional

from rsa import PrivateKey, PublicKey, decrypt, encrypt, newkeys

from AIWithOur.src.const import (
    ELEVATION_REQUIREMENTS_STONES,
    RESOURCE_ABUNDANCE,
)
from AIWithOur.src.state import State
from AIWithOur.src.states import ConnectingState

RSA_FILE: str = "private.pem"


class Context(object):
    _state: Optional[State] = None

    def __init__(self, state: State) -> None:
        self.transition_to(state)
        self.inventory: dict[str, int] = {
            "food": 10,
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        self.level: int = 1
        self.nb_broadcasted: int = 0
        self.is_helping: bool = False
        self.freq: int = 0
        self.client_num: int = 1
        self.missing_resources: list[str] = []
        self.host: str = ""
        self.port: int = 0
        self.team_name: str = ""
        self.socket: socket = socket(AF_INET, SOCK_STREAM)
        self.pubkey: PublicKey = self.generate_keys()
        self.lvl5: bool = False
        self.getting_food: bool = False

    def close(self) -> NoReturn:
        self.socket.close()
        exit(0)

    def transition_to(self, state: State) -> None:
        self._state = state
        self._state.context = self

    def request(self) -> None:
        self._state.handle()

    def connect(self, host: str, port: int, team_name: str) -> None:
        self.host = host
        self.port = port
        self.team_name = team_name
        self.transition_to(ConnectingState())
        self.request()

    def send_message(self, message: str) -> None:
        try:
            self.socket.sendall((message + "\n").encode("utf-8"))
        except Exception:
            self.close()

    def receive_message2(self, use_timeout: bool = False) -> str:
        chunks: list[str] = []
        if use_timeout:
            if int(self.inventory.get("food", 0)) < 5:
                self.socket.settimeout(2 / (self.freq / 10))
            else:
                self.socket.settimeout(5 / (self.freq / 10))
        while True:
            try:
                chunk: bytes = self.socket.recv(1024)
                if not chunk:
                    raise RuntimeError("socket connection broken")
                chunks.append(chunk.decode("utf-8"))
                if len(chunk) < 1024:
                    break
            except BlockingIOError:
                continue
            except timeout:
                return ""
            except RuntimeError:
                self.close()
        return "".join(chunks)

    @staticmethod
    def is_look_response(resultat: str) -> bool:
        return (
            resultat.startswith("[")
            and len(resultat) > 4
            and not resultat[-4].isdigit()
        )

    @staticmethod
    def is_inventory_response(resultat: str) -> bool:
        return resultat.startswith("[") and len(resultat) > 4 and resultat[-4].isdigit()

    def is_attended_response(
        self, resultat: str, original_command: str
    ) -> Optional[bool]:
        commands: list[str] = original_command.split()
        arg: str = commands[1] if len(commands) == 2 else ""
        command: str = commands[0]
        commands_with_ok_response: set[str] = {
            "Forward",
            "Right",
            "Left",
            "Broadcast",
            "Fork",
        }
        if command == "Set":
            if resultat == "ko\n":
                return False
            self.inventory[arg] -= 1
            return True
        if command == "Take":
            if resultat == "ko\n":
                return False
            self.inventory[arg] += 1
            return True
        if command == "Eject":
            return resultat in {"ok\n", "ko\n"}
        if command in commands_with_ok_response:
            return resultat == "ok\n"
        if command == "Look":
            return self.is_look_response(resultat)
        if command == "Inventory":
            return self.is_inventory_response(resultat)
        if command == "Connect_nbr":
            return resultat[:-1].isdigit() if len(resultat) > 1 else False
        return None

    @staticmethod
    def get_direction_to_tile_sound(tile_index: int) -> list[str]:
        commands: list[list[str]] = [
            [],
            ["Forward"],
            ["Forward", "Left", "Forward"],
            ["Left", "Forward"],
            ["Left", "Forward", "Left", "Forward"],
            ["Left", "Left", "Forward"],
            ["Right", "Forward", "Right", "Forward"],
            ["Right", "Forward"],
            ["Forward", "Right", "Forward"],
        ]
        return commands[tile_index]

    def move_in_direction(self, direction: str) -> None:
        if direction == "Forward":
            self.forward()
            nb_food: int = self.look()[0].count("food")
            for _ in range(nb_food):
                self.take("food")
        elif direction == "Right":
            self.right()
        elif direction == "Left":
            self.left()

    @staticmethod
    def calculate_distance(tile_index: int) -> int:
        return int((tile_index**0.5) // 1)

    @staticmethod
    def get_direction_to_tile(tile_index: int, step: int) -> list[str]:
        left: int = step**2
        middle: int = left + step
        forward_commands: list[str] = ["Forward"] * step
        turn_direction: Literal["Left"] | Literal["Right"] = (
            "Left" if tile_index < middle else "Right"
        )
        num_turns: int = abs(tile_index - middle)
        turn_commands: list[str] = [turn_direction] if num_turns != 0 else []
        new_forward_commands: list[str] = ["Forward"] * num_turns
        return forward_commands + turn_commands + new_forward_commands

    def move_to_food(self) -> None:
        tile: int = 0
        nbr_max: int = 0
        look_result: list[list[str]] = self.look()
        tiles_food: list[int] = [
            look_result[i].count("food") for i in range(len(look_result))
        ]
        for i in range(len(tiles_food)):
            if nbr_max < tiles_food[i]:
                nbr_max = tiles_food[i]
                tile = i
        self.get_direction_to_tile(tile, self.calculate_distance(tile))

    def check_for_incantation(self, tile: int) -> None:
        directions: list[str] = self.get_direction_to_tile_sound(tile)
        for direction in directions:
            self.move_in_direction(direction)

    @staticmethod
    def generate_keys() -> PublicKey:
        if path.exists(RSA_FILE):
            with open(RSA_FILE, "rb") as f:
                privkey: PrivateKey = PrivateKey.load_pkcs1(f.read())
            pubkey = PublicKey(privkey.n, privkey.e)
        else:
            (pubkey, privkey) = newkeys(512)
            with open(RSA_FILE, "wb") as f:
                f.write(privkey.save_pkcs1())
        return pubkey

    def encrypt_message(self, message: str) -> str:
        encrypted_bytes: bytes = encrypt(message.encode(), self.pubkey)
        return b64encode(encrypted_bytes).decode()

    @staticmethod
    def decrypt_message(encrypted_message: str) -> str:
        encrypted_bytes: bytes = b64decode(encrypted_message)
        with open(RSA_FILE, "rb") as f:
            privkey: PrivateKey = PrivateKey.load_pkcs1(f.read())
        return decrypt(encrypted_bytes, privkey).decode()

    def move_to_incantation(self, message: str) -> None:
        parts: list[str] = message.split(", ")
        decrypted_message: str = self.decrypt_message(parts[1])
        if "need_players_for_incantation_" not in decrypted_message:
            return
        parts: list[str] = message.split(", ")
        tile = int(parts[0].split(" ")[1])
        try:
            level = int(decrypted_message.rsplit("_", 1)[1])
        except ValueError:
            return
        if self.lvl5 == False and level >= 5:
            self.lvl5 = True
        if self.level == level and int(self.inventory.get("food", "0")) >= 7:
            self.is_helping = True
            self.check_for_incantation(tile)

    def process_level_response(self, response: str) -> None:
        with suppress(ValueError):
            self.level = int(response.split()[2])
            if self.level == 8:
                print("level 8 reached")
                self.close()
            if self.is_helping:
                self.is_helping = False

    def process_response(self, response: str) -> str:
        if response == "dead\n":
            self.close()
        if response.startswith("message"):
            self.move_to_incantation(response)
        if response.startswith("Current level"):
            self.process_level_response(response)
        return self.receive_message2(True)

    def receive_message(self, command: str) -> str:
        response: str = self.receive_message2()
        response = response.split("\n")[0] + "\n"
        while not self.is_attended_response(response, command):
            response = self.process_response(response)
            if not response:
                return ""
        return response

    def connect_number(self) -> int:
        self.send_message("Connect_nbr")
        response: str = self.receive_message("Connect_nbr")
        try:
            return int(response)
        except ValueError:
            return self.connect_number()

    def fork(self) -> None:
        nb: int = self.connect_number()
        if nb != 0:
            Popen(
                [
                    "./zappy_ai_our",
                    "-p",
                    str(self.port),
                    "-n",
                    self.team_name,
                    "-h",
                    self.host,
                ]
            )

    def take(self, obj: str) -> None:
        if obj == "food" and self.level <= 3 and self.inventory.get("food", 0) >= 15:
            return
        if obj == "food" and self.inventory.get("food", 0) >= 30:
            return
        if obj == "thystame" and self.level == 7 and self.inventory.get("thystame", 0) >= 1:
            return
        self.send_message(f"Take {obj}")
        self.receive_message(f"Take {obj}")

    def set(self, obj: str) -> None:
        self.send_message(f"Set {obj}")
        self.receive_message(f"Set {obj}")

    def broadcast(self, message: str) -> None:
        encrypted_message: str = self.encrypt_message(message)
        self.nb_broadcasted += 1
        if self.nb_broadcasted % (int(0.4 * self.freq)) != 0:
            return
        self.send_message(f"Broadcast {encrypted_message}")
        self.receive_message("Broadcast")
        self.nb_broadcasted = 0

    def forward(self) -> None:
        self.send_message("Forward")
        self.receive_message("Forward")

    def right(self) -> None:
        self.send_message("Right")
        self.receive_message("Right")

    def left(self) -> None:
        self.send_message("Left")
        self.receive_message("Left")

    def look(self) -> list[list[str]]:
        self.send_message("Look")
        recv_result: str = self.receive_message("Look")
        tiles: list[str] = recv_result[2:-2].split(",")
        return [tile.split() for tile in tiles]

    def update_missing_resources(self) -> None:
        try:
            food_count = int(self.inventory.get("food", 0))
        except AttributeError:
            food_count = 0
        if food_count <= 5:
            self.missing_resources: list[str] = ["food"]
        else:
            requirements: dict[str, int] = ELEVATION_REQUIREMENTS_STONES[self.level - 1]
            self.missing_resources = [
                item
                for item in requirements
                if int(self.inventory.get(item, 0)) < requirements[item]
            ]
            self.missing_resources.append("food")
            self.missing_resources.sort(
                key=lambda x: (
                    x != "food" if self.level > 4 else 1,
                    RESOURCE_ABUNDANCE.get(x, 1),
                )
            )

    def incantation(self) -> None:
        self.fork()
        self.send_message("Incantation")


class ZappyAI(Context):
    def __init__(self, state: State) -> None:
        super().__init__(state)
