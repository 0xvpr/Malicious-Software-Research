# Position Independent Shellcode

This snippet is an example of how one would generate a custom payload for a 64  
bit windows executable using C and Assembly.

- The payload would be 16 byte aligned so that it [ reason for this ? ]  
- The payload is independent and relies on no other libraries other than the 
  windows headers
