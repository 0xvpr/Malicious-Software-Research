PROJECT  = client.exe

CC       = x86_64-w64-mingw32-gcc
CFLAGS   = -std=c99 -Wall -Wextra -Werror -O2
LDFLAGS  = -lws2_32

BIN      = bin
SRC      = src/main.c

all: debug

debug:
	$(CC) $(SRC) $(CFLAGS) -g -pedantic -DDEBUG $(LDFLAGS) -o $(BIN)/$(PROJECT)

clean:
	rm -fr bin/*
	rm -f  build/*
