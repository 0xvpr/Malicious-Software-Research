# Creating Position Independent Shellcode
First off, credits are due to Dark VortEx.

This snippet is an example of how one would generate a custom payload for a 64  
bit windows executable using C and Assembly.

The strings the utilize the OBF macro will be compile-time encoded in order to  
obfuscate those strings and make detection of intentions more difficult.

- The payload would be 16 byte aligned so that it properly resides in the 
  address space of a 64 bit executable
- The payload is independent and relies on no libraries other than the 
  windows headers
- Section alignment is 16 to further reduce space
- File alignment is 16 to further reduce space

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

## Extracting the Payload
Using vpr-toolkit
```bash
# requires vpr-extract and objdump in path
vpr-extract ./bin/write_hello.exe -O f.bin
```
Using command-line
```bash
# requires objdump in path
for op in $(objdump -d ./bin/write_hello.exe | grep "^ " | cut -f2); do echo -n "\\\\x${op}" >> out.bin; done
```
