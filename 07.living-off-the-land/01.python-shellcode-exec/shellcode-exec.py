#!/usr/bin/env python3.exe

# Created by:       VPR
# Created:          September 25th, 2025

# Updated by:       VPR
# Updated:          September 25th, 2025

# Description:      Executing shellcode from memory using python3 builtins.
# License:          MIT (c) VPR, VPR Labs, et al.

import ctypes
import struct

kernel32 = ctypes.windll.kernel32

def allocate_memory(payload: bytes) -> ctypes.c_voidp:
    payload_size = len(payload)

    kernel32.VirtualAlloc.restype = ctypes.c_voidp
    exec_mem = ctypes.c_void_p(
        kernel32.VirtualAlloc(
            ctypes.c_void_p(0), # nullptr
            payload_size,       # size
            0x3000,             # MEM_COMMIT | MEM_RESERVE
            0x40                # PAGE_EXECUTE_READWRITE
        )
    )
    kernel32.RtlMoveMemory(exec_mem, payload, payload_size)

    return exec_mem

def execute_memory(exec_mem: ctypes.c_void_p) -> None:
    ctypes.cast(exec_mem, ctypes.CFUNCTYPE(None))()

def release_memory(exec_mem: ctypes.c_void_p) -> None:
    payload_size = len(payload)
    exec_mem = kernel32.VirtualAlloc(
        exec_mem,     # nullptr
        payload_size, # size
        0x8000        # MEM_RELEASE
    )

if __name__ == "__main__":
    payload = struct.pack(
        "<BBBB",
        0x90,    # nop
        0x90,    # nop
        0x90,    # nop
        0xC3     # ret
    )

    exec_mem = allocate_memory(payload)
    execute_memory(exec_mem)
    release_memory(exec_mem)
