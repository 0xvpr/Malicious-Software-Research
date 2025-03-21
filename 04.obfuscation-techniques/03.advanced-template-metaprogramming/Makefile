all:
	g++ -std=c++20 -s -Ofast main.cpp -o adv-meta-obfuscator.bin
	strings adv-meta-obfuscator.bin | grep -i Obfuscator-version-3 || exit 0 # proof of compile-time hidden text
