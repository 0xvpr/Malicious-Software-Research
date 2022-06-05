TARGET  = write_hello.exe

CC      = x86_64-w64-mingw32-gcc
CFLAGS  = -m64 -O2 -Wall -Wextra -Werror -nostdlib \
		  -ffunction-sections -fno-asynchronous-unwind-tables -fno-ident \

ASM     = nasm
ASFLAGS = -f win64

LD      = x86_64-w64-mingw32-ld
LDFLAGS = -s --no-seh

BIN     = bin
SRC     = src
OBJ     = build
BUILD   = $(OBJ)
INCLUDE = $(addprefix -I,include)

C_SOURCES   = $(wildcard $(SRC)/*.c)
C_OBJECTS   = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(C_SOURCES))
ASM_SOURCES = $(wildcard $(SRC)/*.asm)
ASM_OBJECTS = $(patsubst $(SRC)/%.asm,$(OBJ)/%.o,$(ASM_SOURCES))

all: $(TARGET)

$(TARGET): $(BIN) $(BUILD) $(SCRIPT) $(ASM_OBJECTS) $(C_OBJECTS)
	$(LD) $(LDFLAGS) $(ASM_OBJECTS) $(C_OBJECTS) -o $(BIN)/$(TARGET)

$(C_OBJECTS): $(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

$(ASM_OBJECTS): $(OBJ)/%.o : $(SRC)/%.asm
	$(ASM) $(ASFLAGS) $^ -o $@

$(BUILD):
	mkdir -p $@

$(BIN):
	mkdir -p $@

clean:
	rm -fr `find . -name "*.o"`
	rm -fr `find . -name "*.exe"`
	rm -fr `find . -name "*.bin"`
