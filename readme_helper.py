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


def generate_navigation(code_directories: List[CodeDirectory]) -> None:
    sys.stdout.write("## Navigation\n")

    for cd in code_directories:
        sys.stdout.write(f"{cd.tag}. [{cd.clean_name}](#{cd.name})\n")

    sys.stdout.write("\n")

def generate_implementation(code_directories: List[CodeDirectory]) -> None:
    sys.stdout.write("### **Code Examples**\n")

    for cd in code_directories:
        sys.stdout.write(f"{cd.tag}. <a name='{cd.name}'>{cd.clean_name}</a>\n")

        # TODO check subdirectories
        for sub_dir in os.listdir(os.curdir + f"/{cd.raw_name}"):
            sub_cd = CodeDirectory(sub_dir)
            sys.stdout.write(f"  - <a href='https://github.com/0xvpr/Malicious-Software-Research/blob/main/{cd.raw_name}/{sub_dir}'>{sub_cd.clean_name}</a>\n")

    sys.stdout.write("\n")
    

#########################


if __name__ == "__main__":
    # cd into project root using script location
    parent_path = PurePath(__file__).parent
    os.chdir(parent_path)

    # Gather all directories in a list
    code_directories = []
    for code_dir in Path(parent_path).iterdir():
        try:
            if int(code_dir.name.split(".")[0]):
                code_directories.append(CodeDirectory(code_dir.name))
        except:
            None

    # Start generating the final list
    generate_navigation(code_directories)
    generate_implementation(code_directories)
