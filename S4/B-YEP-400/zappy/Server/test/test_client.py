##
## EPITECH PROJECT, 2024
## zappy
## File description:
## test_client
##

import socket
import threading
import sys

def receive_messages(sock):
    while True:
        data = sock.recv(1024)
        if not data:
            print("Connection stop, Please make a CTRL C to stop the programme")
            exit(0)
        print(data.decode().rstrip('\n'))

def send_messages(sock):
    while True:
        message = input("") + '\n'
        sock.sendall(message.encode())

def main():
    if (len(sys.argv) != 3):
        print("Please insert on argument the IP server and the port sever")
        return 84
    host = sys.argv[1]
    port = int(sys.argv[2])

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((host, port))

    receive_thread = threading.Thread(target=receive_messages, args=(s,))
    send_thread = threading.Thread(target=send_messages, args=(s,))

    receive_thread.start()
    send_thread.start()

    receive_thread.join()
    send_thread.join()

    s.close()

if __name__ == "__main__":
    main()