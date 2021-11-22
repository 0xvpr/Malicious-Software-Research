#!/usr/bin/env python3

"""
Creator:    VPR
Created:    November 22, 2021
Updated:    November 22, 2021

Description:
    TODO
"""

import sys

KEY = "SECRET_KEY"

def xor(data: bytes, key: str) -> str:
	output_str = ""
	
	key = str(key)
	length = len(key)
	for i in range(len(data)):
		current = data[i]
		current_key = key[i % length]
		output_str += chr(ord(str(current)) ^ ord(current_key))
	
	return output_str

def printCiphertext(ciphertext: str) -> None:
	print('{ 0x' + ', 0x'.join(hex(ord(x))[2:] for x in ciphertext) + ' };')

if __name__ == "__main__":
    try:
        plaintext = open(sys.argv[1], "rb").read()
    except:
        sys.stderr.write(f"Usage: {sys.argv[0]} <path/to/payload>\n")
        sys.exit(-1)

    ciphertext = xor(plaintext, KEY)
    printCiphertext(ciphertext)
