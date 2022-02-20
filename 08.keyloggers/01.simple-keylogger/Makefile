PROJECT = keylogger.exe

CC      = x86_64-w64-mingw32-gcc
CFLAGS  = -std=c99 -O2 -g -pedantic -Wall -Wextra -Werror

LD      = x86_64-w64-mingw32-gcc
LDFLAGS =

SRC     = src
OBJ     = build
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SOURCES))


all: debug

debug: bin build $(OBJECTS)
	$(LD) $(OBJECTS) $(LDFLAGS) -o bin/$(PROJECT)

$(OBJECTS): $(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

bin:
	mkdir -p $@

build:
	mkdir -p $@

clean:
	rm -f bin/*.exe
	rm -f build/*.o
