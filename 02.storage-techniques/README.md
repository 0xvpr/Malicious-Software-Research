# Malicious Software Research - Obfuscation Techniques

This repository contains samples of proof-of-concept writings for Obfuscation techniques available for users of c++, c, and python.

## Table of Contents

1. [Overview](#overview)  
2. [Folder Structure](#folder-structure)  
3. [Getting Started](#getting-started)  
4. [Disclaimer](#disclaimer)  
5. [License](#license)

---

### Overview

- Demonstrate how to levarage the C++ standard for compile-time obfuscation and other quality of life improvements.
- Provide a basis for further experimentation in exploit development, reverse engineering, and malware analysis.

**Please note**: This repository does not provide instructions for malicious use. It exists solely to help researchers, students, and cybersecurity professionals learn how these techniques function so they can defend systems more effectively.

---

### Folder Structure

**01.simple-template-metaprogramming**  
   - Introduces the concept of compile-time obfuscated strings using some compiler tricks.
   - Doesn't work past optimization level 2 on g++/clang++ compilers and /O1 on MSVC++.

**02.intermediate-template-metaprogramming**  
   - Introduces compile-time encryption keys for encoding the payload.
   - Doesn't work past optimization level 2 on g++/clang++ compilers and /O1 on MSVC++.

**03.advanced-template-metaprogramming**  
   - Utilizes compiler black magics for 100% compile-time obfuscated strings and data (to my knowledge and testing).
   - Works on g++/clang++ using -Ofast/O3 optimization and lower.
   - Does not use any stdlibc++ objects for linking making the solution entirely portable and shellcode-friendly.
   - Supports scoped obfuscation and cleanup, as well as a QoL improvement for the calling functionality.

**04.xor**  
   - A basic python script for and example of xor encryption and its implementation.

---

### Getting Started

To experiment with the PoC:

1. **Clone the repository**  
   ```bash
   git clone https://github.com/0xvpr/Malicious-Software-Research
   # Docker image/container scripts can be ran to get a dev environment
   cd 04.obfuscation-techniques
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
