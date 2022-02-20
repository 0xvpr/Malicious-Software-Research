# Malicious Software Research
This is a repository dedicated to researching, documenting, developing,  
and ultimately, **defending** against various strains of malicious software.

## Environment (Requires Docker)
```bash
git clone https://github.com/0xvpr/Malicious-Software-Research
chmod +x build-image.sh run-image.sh
./build-image.sh
./run-image.sh
```

## Navigation
00. [Shellcode Crafting](#shellcode-crafting)
01. [Storage Techniques](#storage-techniques)
02. [Injection Techniques](#injection-techniques)
03. [Obfuscation Techniques](#obfuscation-techniques)
04. [Evasion Techniques](#evasion-techniques)
05. [Ransomware](#ransomware)
06. [Living off the Land](#living-off-the-land)
07. [Client Server Models](#client-server-models)
08. [Keyloggers](#keyloggers)
09. [Droppers](#droppers)
### **Code Examples**
00. <a name="shellcode-crafting">Shellcode Crafting</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/00.shellcode-crafting/01.independent-shellcode">position independent shellcode</a>
01. <a name="storage-techniques">Storage Techniques</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.storage-techniques/01.data">.data</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.storage-techniques/02.text">.text</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/01.storage-techniques/03.rsc">.rsc</a>  
02. <a name="injection-techniques">Injection Techniques</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/02.injection-techniques/01.crt">CreateRemoteThread</a>
03. <a name="obfuscation-techniques">Obfuscation Techniques</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/01.aes">AES encryption</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/02.xor">XOR encryption</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/03.template-metaprogramming">Template Meta-programming</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/03.obfuscation-techniques/03.intermediate-template-metaprogramming">Template Meta-programming</a>
04. <a name="evasion-techniques">Evasion Techniques</a>
05. <a name="ransomware">Ransomware<a/>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/05.ransomware/01.simple-recursive-encryptor">Simple Recursive Encryptor</a>
06. <a name="living-off-the-land">Living off the Land<a/>
07. <a name="client-server-models">Client/Server models<a/>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/07.socket/01.linux-server">Windows Client to Linux Server</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/07.socket/02.python-c2-server">Python based C2 Server</a>
08. <a name="keyloggers">Keyloggers<a/>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/08.keyloggers/01.simple-keylogger">Simple Keylogger (windows)</a>
09. <a name="droppers">Droppers<a/>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/09.keyloggers/01.simple-dropper">Simple Dropper (windows)</a>
  - <a href="https://github.com/0xvpr/Malicious-Software-Research/blob/main/09.keyloggers/02.intermediate-dropper">Intermediate Dropper (windows)</a>

### **Learning Resources**
- Reflective DLL Injection  
    - <a href="https://github.com/rapid7/metasploit-framework/wiki/Using-ReflectiveDll-Injection">MSF Explanation</a>  
- Shellcode Crafting  
    - <a href="https://www.exploit-db.com/docs/english/13610-building-your-own-ud-shellcodes-part-1.pdf">fb1h2s</a>
- Getting Familiar with Sockets
    - <a href="https://www.youtube.com/watch?v=xCEKzqLTvqg&t=1185s">ActiveXSploit</a>
