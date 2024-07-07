##
## EPITECH PROJECT, 2024
## zappy
## File description:
## disconnected_state
##

from __future__ import annotations
from math import ceil
from socket import AF_INET, SOCK_STREAM, socket
from threading import Thread
from time import sleep, time
from typing import Literal

from AIWithOur.src.const import (
    ELEVATION_REQUIREMENTS_PLAYER,
    ELEVATION_REQUIREMENTS_STONES,
    RESOURCE_ABUNDANCE,
)
from AIWithOur.src.state import State


class DisconnectedState(State):
    def handle(self) -> None:
        self.context.transition_to(ConnectingState())
        self.context.request()


class ConnectingState(State):
    def handle(self) -> None:
        try:
            self.context.socket = socket(AF_INET, SOCK_STREAM)
            self.context.socket.connect((self.context.host, self.context.port))
            self.context.receive_message2()
            self.context.transition_to(ConnectedState())
            self.context.request()
        except Exception as e:
            print(f"Failed to connect to server: {e}")
            exit(84)


class ConnectedState(State):
    def decrease_food(self) -> None:
        while True:
            if self.context.inventory["food"] > 0:
                self.context.inventory["food"] -= 1
            else:
                self.context.close()
            sleep(126 / self.context.freq)

    def start_thread(self) -> None:
        thread = Thread(target=self.decrease_food, daemon=True)
        thread.start()

    def get_f(self) -> int:
        start_time: float = time()
        self.context.send_message("Inventory")
        self.context.receive_message("Inventory")
        end_time: float = time()
        elapsed_time: float = end_time - start_time
        return ceil(1 / elapsed_time)

    def handle(self) -> None:
        self.context.send_message(self.context.team_name)
        recv: str = self.context.receive_message2()
        if "ko" in recv:
            exit(84)
        try:
            self.start(recv)
        except ValueError:
            exit(84)

    def start(self, recv: str) -> None:
        self.context.client_num = int(recv.split("\n")[0])
        self.context.freq = self.get_f() * 2
        self.start_thread()
        self.context.transition_to(IdleState())
        self.context.request()


class IncantingState(State):
    def drop_required_items(self) -> None:
        requirements: dict[str, int] = ELEVATION_REQUIREMENTS_STONES[
            self.context.level - 1
        ]
        for item, count in requirements.items():
            for _ in range(count):
                if (
                    item in self.context.inventory
                    and int(self.context.inventory[item]) > 0
                ):
                    self.context.set(item)

    def count_players_on_tile(self) -> int:
        self.context.send_message("Look")
        look_result: str = self.context.receive_message("Look")
        first_tile_content: list[str] = look_result[1:-1].split(",")[0].split()
        return first_tile_content.count("player")

    def process_incantation(self) -> None:
        if self.context.level != 1:
            self.drop_required_items()
        self.context.incantation()

    def handle(self) -> None:
        required_players: int = ELEVATION_REQUIREMENTS_PLAYER[self.context.level - 1]
        if required_players == 1:
            self.process_incantation()
            return
        current_players: int = self.count_players_on_tile()
        if current_players >= required_players:
            self.process_incantation()
        else:
            self.context.broadcast(f"need_players_for_incantation_{self.context.level}")
        self.context.transition_to(IdleState())
        self.context.request()


class GatheringResourcesState(State):
    def move_towards_resource(self, found_resources: list[tuple[int, str]]) -> None:
        found_resources_with_distance: list[tuple[int, str, int]] = [
            (idx, resource, self.context.calculate_distance(idx))
            for idx, resource in found_resources
        ]
        found_resources_with_distance.sort(
            key=lambda x: (x[2], RESOURCE_ABUNDANCE[x[1]])
        )
        resource_tile, _, step = found_resources_with_distance[0]
        directions: list[str] = self.context.get_direction_to_tile(resource_tile, step)
        for direction in directions:
            self.context.move_in_direction(direction)

    def go_to_random_direction(self) -> None:
        directions: list[str] = ["Forward"] * self.context.level
        for direction in directions:
            self.context.move_in_direction(direction)

    def find_resources(self) -> None:
        tiles: list[list[str]] = self.context.look()
        found_resources: list[tuple[int, str]] = []
        for idx, tile in enumerate(tiles):
            found_resources.extend(
                (idx, resource)
                for resource in self.context.missing_resources
                if resource in tile
            )
        if found_resources:
            self.move_towards_resource(found_resources)
        else:
            self.go_to_random_direction()

    def process_elevation_requirements(self) -> None:
        requirements: dict[str, int] = ELEVATION_REQUIREMENTS_STONES[
            self.context.level - 1
        ]
        for item, count in requirements.items():
            for _ in range(count):
                if (
                    item in self.context.inventory
                    and int(self.context.inventory[item]) > 0
                ):
                    self.context.set(item)
        self.context.incantation()

    def process_missing_resource(self, obj: str) -> None:
        missing_resources_without_food: list[str] = [
            resource
            for resource in self.context.missing_resources
            if resource != "food"
        ]
        if (
            len(missing_resources_without_food) == 1
            and missing_resources_without_food[0] == obj
            and self.context.level == 1
        ):
            self.process_elevation_requirements()
            return
        self.context.take(obj)

    def process_tile(self, tile: list[str]) -> None:
        for obj in tile:
            if obj in self.context.missing_resources:
                self.process_missing_resource(obj)

    def handle(self) -> None:
        self.find_resources()
        self.process_tile(self.context.look()[0])
        self.context.transition_to(IdleState())
        self.context.request()


class IdleState(State):
    def handle(self) -> None:
        if self.context.getting_food == True:
            self.context.move_to_food()
            if self.context.inventory.get("food", 0) >= 20:
                self.context.getting_food = False
        elif self.context.level >= 6 and self.context.inventory.get("food", 0) <= 5:
            self.context.move_to_food()
            self.context.getting_food = True
        self.context.update_missing_resources()
        if [
            resource
            for resource in self.context.missing_resources
            if resource != "food"
        ] or int(self.context.inventory.get("food", "0")) < 10:
            self.context.transition_to(GatheringResourcesState())
        else:
            self.context.transition_to(IncantingState())
        self.context.request()
