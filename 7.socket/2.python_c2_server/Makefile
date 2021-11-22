PROJECT  = client.exe

CC       = x86_64-w64-mingw32-g++
CFLAGS   = -std=c++2a -Wall -Wextra -Werror -O2
LDFLAGS  = -static-libstdc++ -static-libgcc -lws2_32

BIN      = bin
SRC      = src/Main.cpp

all:
	$(CC) $(SRC) $(CFLAGS) -g -pedantic -DDEBUG $(LDFLAGS) -o $(BIN)/$(PROJECT)

release:
	$(CC) $(SRC) $(CFLAGS) -s -fno-ident $(LDFLAGS) -o $(BIN)/$(PROJECT)

clean:
	rm -fr $(BIN)/$(PROJECT)
