PROJECT = ransomware

CC      = x86_64-w64-mingw32-gcc
CFLAGS  = -std=c99 -O2 -g -pedantic -Wall -Wextra -Werror

LD      = x86_64-w64-mingw32-gcc
LDFLAGS =

BIN     = bin
BUILD   = build

SRC     = src
OBJ     = $(BUILD)
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SOURCES))


all: debug

debug: $(BIN)/$(PROJECT)_d.exe

$(BIN)/$(PROJECT)_d.exe: $(BIN) $(BUILD) $(OBJECTS) test_dir
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(BIN):
	mkdir -p $@

$(BUILD):
	mkdir -p $@

test_dir:
	mkdir -p $@
	echo "this is a test of the text to be encoded 1." > $@/1.txt
	echo "this is a test of the text to be encoded 2." > $@/2.txt
	echo "this is a test of the text to be encoded 3." > $@/3.txt

clean:
	rm -f $(BIN)/*.exe*
	rm -f $(OBJECTS)
	rm -fr test_dir
