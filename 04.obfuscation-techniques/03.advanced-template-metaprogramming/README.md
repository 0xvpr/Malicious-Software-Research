# Advanced Template Meta-Programming
This strategy attempts to hide strings at compile-time and leave them hidden  
until they are revealed at runtime, even when compiled with **maximum optimization**.
The encryption method used here is a compile time random key. This demo encrypts  
a string literal and replaces it with a call to de-obfuscation routine.

- Works for all optimization levels (tested on g++ and clang++ for -O0/O1/O2/O3/Ofast)
- Lives only in the scope of the construction with a PoC for cleanup.

### Building (output as .bin to prevent execution)
```bash
make # should return 0 if successful
```
