# Malicious Software Research - Hooking Techniques

This repository contains research-oriented shellcode and syscall examples meant to illustrate various techniques for hooking function calls, thread routines, shared objects, and etc... **All code and information provided here is for educational and research purposes only.** Use it responsibly and ethically.

## Table of Contents

1. [Overview](#overview)  
2. [Folder Structure](#folder-structure)  
3. [Getting Started](#getting-started)  
4. [Disclaimer](#disclaimer)  
5. [License](#license)

---

### Overview

Malware research requires a thorough understanding of how shellcode and syscalls work at an assembly level. This repository’s examples are meant to:

- Demonstrate how to write hooking techniques using various approaches (more specifically for x86 architecture).

**Please note**: This repository does not provide instructions for malicious use. It exists solely to help researchers, students, and cybersecurity professionals learn how these techniques function so they can defend systems more effectively.

---

### Folder Structure

**01.absolute-jmp-detour**
    - Demonstrates how a detour function could be constructed and implemented.

**02.absolute-jmp-detour-once**
    - Demonstrates how a single use detour function could be constructed and implemented.

**03.relative-jmp-detour**
    - Demonstrates how a relative jmp object could be constructed and implemented.

---

### Getting Started

To experiment with the shellcode:

1. **Clone the repository**  
   ```bash
   git clone https://github.com/0xvpr/Malicious-Software-Research
   cd 11.hooking-techniques
   ```

### <a href="../DISCLAIMER.md">Disclaimer</a>
- Educational Use Only: All examples and code herein are for educational and research purposes only.
- No Warranty: The repository is provided “as is”, without warranty of any kind, express or implied.
- Legal Responsibility: You are solely responsible for ensuring that your use of these materials complies with all applicable laws and regulations.

If you have any doubts regarding the legality or ethics of using these examples, do not proceed.

### <a href="../LICENSE">License</a>
This repository is released under the MIT License. In short:
- You are free to use, modify, and distribute this code for personal or commercial purposes.
- Please include credit where credit is due.
- The authors/contributors are not liable for any misuse or damage caused by this code.
