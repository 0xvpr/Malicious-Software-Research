# Malicious Software Research - Shellcode Crafting

This repository contains research-oriented shellcode and syscall examples meant to illustrate various techniques for crafting low-level payloads. **All code and information provided here is for educational and research purposes only.** Use it responsibly and ethically.

## Table of Contents

1. [Overview](#overview)  
2. [Folder Structure](#folder-structure)  
3. [Getting Started](#getting-started)  
4. [Disclaimer](#disclaimer)  
5. [License](#license)

---

### Overview

Malware research requires a thorough understanding of how shellcode and syscalls work at an assembly level. This repository’s examples are meant to:

- Demonstrate how to write simple shellcode and more advanced shellcode payloads.  
- Show the difference between shellcode relying on common libraries/functions and pure syscall-based approaches.  
- Provide a basis for further experimentation in exploit development, reverse engineering, and malware analysis.

**Please note**: This repository does not provide instructions for malicious use. It exists solely to help researchers, students, and cybersecurity professionals learn how these techniques function so they can defend systems more effectively.

---

### Folder Structure

**01.independent-shellcode**  
   - Contains standalone shellcode samples that do not rely heavily on external libraries or imports.  
   - Demonstrates basic concepts such as setting up registers, calling `execve`/`WinExec` (depending on the OS), and small payload design.

**02.adv-independent-shellcode**  
   - Builds upon the basic shellcode by introducing more advanced techniques.  
   - May include encoder/decoder stubs, staging payloads, or techniques to bypass certain protections.  
   - Highlights ways to reduce shellcode footprint or dynamically resolve API calls.

**03-pure-assembly-syscall**  
   - Focuses on pure assembly examples that directly invoke system calls without relying on high-level library functions.  
   - Illustrates low-level mechanics on both Linux and Windows (if samples for both OSes are included).  
   - Useful for learning how to manually set up syscall numbers, parameters, and handle return values.

---

### Getting Started

To experiment with the shellcode:

1. **Clone the repository**  
   ```bash
   git clone https://github.com/0xvpr/Malicious-Software-Research
   cd 00.shellcode-crafting
   ```

### Disclaimer
- Educational Use Only: All examples and code herein are for educational and research purposes only.
- No Warranty: The repository is provided “as is”, without warranty of any kind, express or implied.
- Legal Responsibility: You are solely responsible for ensuring that your use of these materials complies with all applicable laws and regulations.

If you have any doubts regarding the legality or ethics of using these examples, do not proceed.

### <a href="../LICENSE">License</a>
This repository is released under the MIT License. In short:
- You are free to use, modify, and distribute this code for personal or commercial purposes.
- Please include credit where credit is due.
- The authors/contributors are not liable for any misuse or damage caused by this code.