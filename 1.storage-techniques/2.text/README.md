# Storing Payloads in .text

This method of storing the payload revolves around the use of a character  
array that resides inside of the scope of our main function:
```
#include <stdio.h>

int main(void)
{
    unsigned char payload[4] = {
        0x90,  // nop
        0x90,  // nop
        0xCC,  // int3
        0xC3   // ret
    };
    size_t size = 4;

    (...)
```
