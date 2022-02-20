# Intermediate Template Meta-Programming
This strategy attempts to hide strings at compile-time and leave them hidden  
until they are revealed at runtime. The encryption method used here is a  
compile time random key. This demo encrypts a string literal and  
replaces it with a call to de-obfuscation routine.

### Build & Run
```bash
make && ./obfuscated-string.exe
```
