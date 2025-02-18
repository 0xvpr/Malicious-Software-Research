PROJECT = obfuscated-string

CC      = x86_64-w64-mingw32-g++-posix
CFLAGS  = -std=c++17 -O2 -Wall -Wextra -Werror
LDFLAGS = -s

SOURCES = Main.cpp

all: release

debug:
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -g -DDEBUG -o $(PROJECT)_d.exe

release:
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -DNDEBUG -o $(PROJECT).exe


.PHONY: clean
	rm -fr obfuscated-string.exe
