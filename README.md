<h1 align="center">Malicious Software Research</h1>
<p align="center">
  <a href="https://mit-license.org/">
    <img src="https://img.shields.io/github/license/0xvpr/Malicious-Software-Research?style=flat-square">
  </a>
  <br>
  <h3 align="left">A repository dedicated to researching, analyzing, documenting,
and ultimately, <i>defending</i> against various strains of malicious software and their behaviors.</h3>
  <br>
</p>

## Table of Contents
- [Environment](#environment)
- [Code Examples](#code-examples)
    01. [Shellcode Crafting](#shellcode-crafting)
    02. [Storage Techniques](#storage-techniques)
    03. [Injection Techniques](#injection-techniques)
    04. [Obfuscation Techniques](#obfuscation-techniques)
    05. [Ransomware](#ransomware)
    06. [Evasion](#evasion)
    07. [Living Off The Land](#living-off-the-land)
    08. [Socket](#socket)
    09. [Keyloggers](#keyloggers)
    10. [Droppers](#droppers)
    11. [Hooking Techniques](#hooking-techniques)
- [Credits & Learning Resources](#credits--learning-resources)
- [Disclaimer](#disclaimer)
- [License](#license)

---

### Environment
```bash
git clone https://github.com/0xvpr/Malicious-Software-Research
cd Malicious-Software-Research
chmod +x build-image.sh run-image.sh
./build-image.sh
./run-image.sh
```

---

### Code Examples
01. <a name='shellcode-crafting'>Shellcode Crafting</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.shellcode-crafting/01.independent-shellcode'>Independent Shellcode</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.shellcode-crafting/02.adv-independent-shellcode'>Adv Independent Shellcode</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.shellcode-crafting/03.pure-assembly-syscall'>Pure Assembly Syscall</a>
02. <a name='storage-techniques'>Storage Techniques</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/02.storage-techniques/01.data'>Data</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/02.storage-techniques/02.text'>Text</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/02.storage-techniques/03.rsc'>Rsc</a>
03. <a name='injection-techniques'>Injection Techniques</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.injection-techniques/01.crt'>Crt</a>
04. <a name='obfuscation-techniques'>Obfuscation Techniques</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/04.obfuscation-techniques/01.simple-template-metaprogramming'>Simple Template Metaprogramming</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/04.obfuscation-techniques/02.intermediate-template-metaprogramming'>Intermediate Template Metaprogramming</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/04.obfuscation-techniques/03.advanced-template-metaprogramming'>Advanced Template Metaprogramming</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/04.obfuscation-techniques/04.xor'>Xor</a>
05. <a name='ransomware'>Ransomware</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/05.ransomware/01.simple-recursive-encryptor'>Simple Recursive Encryptor</a>
06. <a name='evasion'>Evasion</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/06.evasion/01.anti-dynamic-analysis-techniques'>Anti Dynamic Analysis Techniques</a>
07. <a name='living-off-the-land'>Living Off The Land</a>
08. <a name='socket'>Socket</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/08.socket/1.linux-server'>Linux Server</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/08.socket/2.python-c2-server'>Python C2 Server</a>
09. <a name='keyloggers'>Keyloggers</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/09.keyloggers/01.simple-keylogger'>Simple Keylogger</a>
10. <a name='droppers'>Droppers</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/10.droppers/01.simple-dropper'>Simple Dropper</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/10.droppers/02.intermediate-dropper'>Intermediate Dropper</a>
11. <a name='hooking-techniques'>Hooking Techniques</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/11.hooking-techniques/01.absolute-jmp-detour'>Absolute Jmp Detour</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/11.hooking-techniques/02.absolute-jmp-detour-once'>Absolute Jmp Detour Once</a>
    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/11.hooking-techniques/03.relative-jmp-detour'>Relative Jmp Detour</a>

### Credits & Learning Resources
- Reversing C++ Classes and Structures
  - <a href="https://www.blackhat.com/presentations/bh-dc-07/Sabanal_Yason/Paper/bh-dc-07-Sabanal_Yason-WP.pdf">Paul Vincent Sabanal & Mark Vincent Yason</a>
- Reflective DLL Injection  
  - <a href="https://github.com/rapid7/metasploit-framework/wiki/Using-ReflectiveDll-Injection">MSF Explanation</a>  
- Executing Position Independent Shellcode from Object Files in Memory
  - <a href="https://bruteratel.com/research/feature-update/2021/01/30/OBJEXEC/">Dark VortEx</a>  
- Shellcode Crafting  
  - <a href="https://www.exploit-db.com/docs/english/13610-building-your-own-ud-shellcodes-part-1.pdf">fb1h2s</a>
- Getting Familiar with Sockets
  - <a href="https://www.youtube.com/watch?v=xCEKzqLTvqg&t=1185s">ActiveXSploit</a>
- Anti Dynamic Analysis & Sandboxes
  - <a href="https://0xpat.github.io/Malware_development_part_2/">0xPat</a>
- Anti Debugging
  - <a href="https://0xpat.github.io/Malware_development_part_3/">0xPat</a>
- Anti Static Analysis Tricks
  - <a href="https://0xpat.github.io/Malware_development_part_4/">0xPat</a>
### <a href="DISCLAIMER.md">Disclaimer</a>
- Educational Use Only: All examples and code herein are for educational and research purposes only.
- No Warranty: The repository is provided “as is”, without warranty of any kind, express or implied.
- Legal Responsibility: You are solely responsible for ensuring that your use of these materials complies with all applicable laws and regulations.

If you have any doubts regarding the legality or ethics of using these examples, do not proceed.

### <a href="LICENSE">License</a>
This repository is released under the MIT License. In short:
- You are free to use, modify, and distribute this code for personal or commercial purposes.
- Please include credit where credit is due.
- The authors/contributors are not liable for any misuse or damage caused by this code.
