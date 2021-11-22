# Creating Position Independent Shellcode

This snippet is an example of how one would generate a custom payload for a 64  
bit windows executable using C and Assembly.

- The payload would be 16 byte aligned so that it properly resides in the 
  address space of a 64 bit executable
- The payload is independent and relies on no libraries other than the 
  windows headers

A very important component is the **linker.ld** file. This file instructs the  
linker to use this script to use the entry point and control flow that we want.
```
ENTRY(alignstack)
SECTIONS
{
    .text :
    {
        *(.text.alignstack)
        *(.text.write_hello)
    }
}
```
