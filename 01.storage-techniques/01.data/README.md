# Storing Payloads in .data

This method of storing the payload revolves around the use of a character  
array that resides outside of the scope of our main function:
```
#include <stdio.h>

unsigned char payload[4] = {
    0x90,  // nop
    0x90,  // nop
    0xCC,  // int3
    0xC3   // ret
};
size_t size = 4;

int main(void)
{
    (...)
```
