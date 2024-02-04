# Malicious Software Research
This is a repository dedicated to researching, documenting, developing,  
and ultimately, **defending** against various strains of malicious software.

## Environment (Requires Docker)
```bash
git clone https://github.com/0xvpr/Malicious-Software-Research
cd Malicious-Software-Research
chmod +x build-image.sh run-image.sh
./build-image.sh
./run-image.sh
```

## Navigation
01. [Storage Techniques](storage-techniques)
02. [Injection Techniques](injection-techniques)
03. [Obfuscation Techniques](obfuscation-techniques)
04. [Evasion](evasion)
05. [Ransomware](ransomware)
06. [Living Off The Land](living-off-the-land)
07. [Socket](socket)
08. [Keyloggers](keyloggers)
09. [Droppers](droppers)
10. [Hooking Techniques](hooking-techniques)

### **Code Examples**
01. <a name='storage-techniques'>Storage Techniques</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.storage-techniques/01.data'>Data</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.storage-techniques/02.text'>Text</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.storage-techniques/03.rsc'>Rsc</a>
02. <a name='injection-techniques'>Injection Techniques</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/02.injection-techniques/01.crt'>Crt</a>
03. <a name='obfuscation-techniques'>Obfuscation Techniques</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/01.aes'>Aes</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/02.xor'>Xor</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/03.simple-template-metaprogramming'>Simple Template Metaprogramming</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/04.intermediate-template-metaprogramming'>Intermediate Template Metaprogramming</a>
04. <a name='evasion'>Evasion</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/04.evasion/01.anti-dynamic-analysis-techniques'>Anti Dynamic Analysis Techniques</a>
05. <a name='ransomware'>Ransomware</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/05.ransomware/01.simple-recursive-encryptor'>Simple Recursive Encryptor</a>
06. <a name='living-off-the-land'>Living Off The Land</a>
07. <a name='socket'>Socket</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/07.socket/1.linux-server'>Linux Server</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/07.socket/2.python-c2-server'>Python C2 Server</a>
08. <a name='keyloggers'>Keyloggers</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/08.keyloggers/01.simple-keylogger'>Simple Keylogger</a>
09. <a name='droppers'>Droppers</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/09.droppers/01.simple-dropper'>Simple Dropper</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/09.droppers/02.intermediate-dropper'>Intermediate Dropper</a>
10. <a name='hooking-techniques'>Hooking Techniques</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/10.hooking-techniques/01.absolute-jmp-detour'>Absolute Jmp Detour</a>
  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/10.hooking-techniques/02.absolute-jmp-detour-once'>Absolute Jmp Detour Once</a>


### **Learning Resources**
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
