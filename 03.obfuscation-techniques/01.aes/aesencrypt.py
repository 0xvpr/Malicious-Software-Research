#!/usr/bin/env python3

"""
Creator:    VPR
Created:    November 22, 2021
Updated:    November 22, 2021

Description:
    TODO
"""

import hashlib
import sys
import os

from Crypto.Cipher import AES #pip install pycrypto

KEY = os.urandom(16)

def pad(s) -> bytes:
	return s + (AES.block_size - len(s) % AES.block_size) * chr(AES.block_size - len(s) % AES.block_size)

def aesenc(plaintext: bytes, key: bytes):
	k = hashlib.sha256(key).digest()
	iv = 16 * '\x00'
	plaintext = pad(plaintext)
	cipher = AES.new(k, AES.MODE_CBC, iv)

	return cipher.encrypt(bytes(plaintext))

if __name__ == "__main__":
    try:
        plaintext = open(sys.argv[1], "rb").read()
    except:
        sys.stderr.write(f"Usage: {sys.argv[0]} <path/to/payload>\n")
        sys.exit(-1)

    ciphertext = aesenc(plaintext, KEY)

    print('AESkey[] = { 0x' + ', 0x'.join(hex(ord(str(x)))[2:] for x in KEY) + ' };')
    print('payload[] = { 0x' + ', 0x'.join(hex(ord(str(x)))[2:] for x in ciphertext) + ' };')
