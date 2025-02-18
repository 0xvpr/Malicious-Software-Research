#!/usr/bin/env python3

import os
import sys

from pathlib import (
    PurePath,
    Path
)

from typing import List


#########################


class CodeDirectory(object):
    def __init__(self, directory: str):
        self.raw_name = directory
        self.tag, self.name = directory.split(".")
        self.clean_name = self.name.replace("-", " ").title()


#########################

def generate_header() -> None:
    sys.stdout.write('<h1 align="center">Malicious Software Research</h1>\n')
    sys.stdout.write('<p align="center">\n')
    sys.stdout.write('  <a href="https://mit-license.org/">\n')
    sys.stdout.write('    <img src="https://img.shields.io/github/license/0xvpr/Malicious-Software-Research?style=flat-square">\n')
    sys.stdout.write('  </a>\n')
    sys.stdout.write('  <br>\n')
    sys.stdout.write('  <h3 align="left">A repository dedicated to researching, analyzing, documenting,\n')
    sys.stdout.write('and ultimately, <i>defending</i> against various strains of malicious software and their behaviors.</h3>\n')
    sys.stdout.write('  <br>\n')
    sys.stdout.write('</p>\n\n')

def generate_navigation(code_directories: List[CodeDirectory]) -> None:
    sys.stdout.write("## Table of Contents\n")

    sys.stdout.write("- [Environment](#environment)\n")
    sys.stdout.write("- [Code Examples](#code-examples)\n")
    for cd in code_directories:
        sys.stdout.write(f"    {cd.tag}. [{cd.clean_name}](#{cd.name})\n")
    sys.stdout.write("- [Credits & Learning Resources](#credits--learning-resources)\n")
    sys.stdout.write("- [Disclaimer](#disclaimer)\n")
    sys.stdout.write("- [License](#license)\n")

    sys.stdout.write("\n")

def generate_implementation(code_directories: List[CodeDirectory]) -> None:
    sys.stdout.write("---\n\n")
    sys.stdout.write("### Environment\n")
    sys.stdout.write("```bash\n")
    sys.stdout.write("git clone https://github.com/0xvpr/Malicious-Software-Research\n")
    sys.stdout.write("cd Malicious-Software-Research\n")
    sys.stdout.write("chmod +x build-image.sh run-image.sh\n")
    sys.stdout.write("./build-image.sh\n")
    sys.stdout.write("./run-image.sh\n")
    sys.stdout.write("```\n")
    sys.stdout.write("\n")
    sys.stdout.write("---\n\n")

    sys.stdout.write("### Code Examples\n")
    for cd in code_directories:
        sys.stdout.write(f"{cd.tag}. <a name='{cd.name}'>{cd.clean_name}</a>\n")

        # TODO check subdirectories
        for sub_dir in os.listdir(os.curdir + f"/{cd.raw_name}"):
            if not Path(sub_dir).is_file():
              sub_cd = CodeDirectory(sub_dir)
              sys.stdout.write(f"    - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/{cd.raw_name}/{sub_dir}'>{sub_cd.clean_name}</a>\n")

    sys.stdout.write("\n")

def generate_footer() -> None:
    sys.stdout.write("### Credits & Learning Resources\n")
    sys.stdout.write('- Reversing C++ Classes and Structures\n')
    sys.stdout.write('  - <a href="https://www.blackhat.com/presentations/bh-dc-07/Sabanal_Yason/Paper/bh-dc-07-Sabanal_Yason-WP.pdf">Paul Vincent Sabanal & Mark Vincent Yason</a>\n')
    sys.stdout.write('- Reflective DLL Injection  \n')
    sys.stdout.write('  - <a href="https://github.com/rapid7/metasploit-framework/wiki/Using-ReflectiveDll-Injection">MSF Explanation</a>  \n')
    sys.stdout.write('- Executing Position Independent Shellcode from Object Files in Memory\n')
    sys.stdout.write('  - <a href="https://bruteratel.com/research/feature-update/2021/01/30/OBJEXEC/">Dark VortEx</a>  \n')
    sys.stdout.write('- Shellcode Crafting  \n')
    sys.stdout.write('  - <a href="https://www.exploit-db.com/docs/english/13610-building-your-own-ud-shellcodes-part-1.pdf">fb1h2s</a>\n')
    sys.stdout.write('- Getting Familiar with Sockets\n')
    sys.stdout.write('  - <a href="https://www.youtube.com/watch?v=xCEKzqLTvqg&t=1185s">ActiveXSploit</a>\n')
    sys.stdout.write('- Anti Dynamic Analysis & Sandboxes\n')
    sys.stdout.write('  - <a href="https://0xpat.github.io/Malware_development_part_2/">0xPat</a>\n')
    sys.stdout.write('- Anti Debugging\n')
    sys.stdout.write('  - <a href="https://0xpat.github.io/Malware_development_part_3/">0xPat</a>\n')
    sys.stdout.write('- Anti Static Analysis Tricks\n')
    sys.stdout.write('  - <a href="https://0xpat.github.io/Malware_development_part_4/">0xPat</a>\n')
    sys.stdout.write('### <a href="../LICENSE">Disclaimer</a>\n')
    sys.stdout.write('- Educational Use Only: All examples and code herein are for educational and research purposes only.\n')
    sys.stdout.write('- No Warranty: The repository is provided “as is”, without warranty of any kind, express or implied.\n')
    sys.stdout.write('- Legal Responsibility: You are solely responsible for ensuring that your use of these materials complies with all applicable laws and regulations.\n')
    sys.stdout.write('\n')
    sys.stdout.write('If you have any doubts regarding the legality or ethics of using these examples, do not proceed.\n')
    sys.stdout.write('\n')
    sys.stdout.write('### <a href="../LICENSE">License</a>\n')
    sys.stdout.write('This repository is released under the MIT License. In short:\n')
    sys.stdout.write('- You are free to use, modify, and distribute this code for personal or commercial purposes.\n')
    sys.stdout.write('- Please include credit where credit is due.\n')
    sys.stdout.write('- The authors/contributors are not liable for any misuse or damage caused by this code.\n')


#########################


if __name__ == "__main__":
    # cd into project root using script location
    parent_path = PurePath(__file__).parent
    os.chdir(parent_path)

    # Gather all directories in a list
    code_directories = []
    for code_dir in Path(parent_path).iterdir():
        try:
            tokens = code_dir.name.split(".")
            if code_dir.is_dir() and len(tokens) > 1 and int(tokens[0]) >= 0:
                code_directories.append(CodeDirectory(code_dir.name))
        except:
            None

    # Start generating the final list
    generate_header()
    generate_navigation(code_directories)
    generate_implementation(code_directories)
    generate_footer()