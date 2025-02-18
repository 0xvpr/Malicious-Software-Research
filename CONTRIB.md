# Contributions

Thank you for your interest in contributing to our Malicious Software Research repository. This project is dedicated to studying and documenting different techniques used by malicious software, strictly for educational and research purposes.
Your contributions are invaluable in helping security researchers, malware analysts, and enthusiasts deepen their understanding of malicious software, its behavior, and possible countermeasures.

---

1. Important Disclaimer

    Ethical Use Only: The content provided here is meant solely for research, defense, and educational purposes. It should never be used for unlawful or unethical activities.
    No Warranty: This repository and its contents are provided “as is,” without warranty of any kind.

2. Repository Structure

The repository’s core directory for techniques is located at the root of the repository. Primary technique genres are denoted by a digit prefix (i.e. 05) and Each sub-directory within a Primary technique genre represents a unique malware technique. A typical structure looks like this:

```bash
[index].primary-technique-genre                   <-- Primary technique
├── [next_available_index].technique       <-- Technique folder (e.g., "1.technique")
│   ├── README.md                          <-- Documentation for this technique
│   ├── bin
│   │   └── mw.exe                         <-- Compiled or packaged binaries
│   ├── build
│   │   └── obj.o                          <-- Build output objects
│   ├── build-system-file                  <-- Build or configuration file (e.g., Makefile)
│   └── src
│       └── source.code                    <-- Primary source code
└── README.md                              <-- High-level README describing .malware-technique-genre
```

### Naming Conventions
    Technique Folder: Named sequentially based on the next available index, followed by .technique. For example, 1.technique, 2.technique, etc.
    Source Code: Place all main source code files in the src folder.
    Build Artifacts: Keep compiled objects and binaries in the build and bin folders, respectively.
    Documentation: Each technique folder must have a README.md that describes the technique, requirements, compilation steps, usage, and any relevant security implications.

3. Adding a New Technique

    Check the Index: Identify the next available index by looking at the existing folders under .malware-technique-genre. If the highest is 3.technique, yours should be 4.technique.
    Create a New Folder: Name the folder [newIndex].technique inside .malware-technique-genre.
    Populate Structure:
        Add a README.md describing the malware technique, references, potential detection strategies, etc.
        Create src/ and place your source code in it.
        Create build/ and bin/ folders as needed.
        If you are using a build system (Make, CMake, etc.), include the build file at the root of your technique folder (e.g., build-system-file).
    Document Thoroughly: Include usage details, disclaimers, and any instructions or dependencies required to run or analyze your technique.

4. Coding Guidelines

    Language Choice: You are free to use any language (C, C++, Python, Assembly, Rust, etc.) as long as you include build instructions or environment setup guides.
    Commenting & Documentation:
        Write clear comments explaining key functions or unusual code blocks.
        Update each technique’s README.md to provide context and usage examples.
    Security Practices: Even though these samples may be inherently malicious, practice secure coding standards. Avoid distributing actual malicious binaries without disclaimers or obfuscation in place for dangerous sections.

5. Pull Request Process

    Fork this repository to your own GitHub account.
    Clone your fork locally.
    Branch out for your new technique or bug fix (e.g., feature/new-technique or fix/typo-technique2).
    Implement your changes, respecting the Repository Structure and Coding Guidelines.
    Commit your changes with a clear commit message (e.g., Add new keylogging technique, update README).
    Push to your fork.
    Open a Pull Request against the main repository.
    Review: The maintainers or community may request changes. Address them promptly.

Your Pull Request will be merged once it meets all structural, documentation, and code quality requirements.

6. Security & Responsible Disclosure  
**If you find any potential security issues or dangerous code that could be abused beyond research:**  
**Immediately report it via a private channel.**  
**We will work together to determine the next steps to ensure the content is responsibly disclosed or removed if necessary.**

7. Community Guidelines

    Respect fellow contributors and researchers.
    Stay on topic: This repository focuses on analyzing and educating about malware techniques. Off-topic or unrelated content may be declined.
    No Encouragement of Illegal Activity: Any content or discussion that encourages the use of these techniques for illicit purposes will be removed.

8. Contact

    Reach out to the repository owner or open an issue for general queries.
    For private or sensitive matters (e.g., security disclosures), use admin@0xvpr.io.

We appreciate your interest and contributions to the Malicious Software Research repository. Together, we can help the cybersecurity community stay informed and prepared against evolving threats.

© 2025 Malicious Software Research. All rights reserved.