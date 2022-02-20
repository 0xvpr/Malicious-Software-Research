TARGET  = write_hello.exe
SCRIPT  = linker.ld

CC      = x86_64-w64-mingw32-gcc
CFLAGS  = -m64 -O2 -Wall -Wextra -Werror -nostdlib \
		  -ffunction-sections -fno-asynchronous-unwind-tables -fno-ident \
		  -Wl,-T$(SCRIPT),--no-seh

ASM     = nasm
ASFLAGS = -f win64

LD      = x86_64-w64-mingw32-ld
LDFLAGS = -s

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

$(SCRIPT):
	echo "ENTRY(alignstack)"             > $(SCRIPT)
	echo "SECTIONS"                     >> $(SCRIPT)
	echo "{"                            >> $(SCRIPT) 
	echo "    .text :"                  >> $(SCRIPT)
	echo "    {"                        >> $(SCRIPT)
	echo "        *(.text.alignstack)"  >> $(SCRIPT)
	echo "        *(.text.write_hello)" >> $(SCRIPT)
	echo "    }"                        >> $(SCRIPT)
	echo "}"                            >> $(SCRIPT)

$(BUILD):
	mkdir -p $@

$(BIN):
	mkdir -p $@

clean:
	rm -fr `find . -name "*.o"`
	rm -fr `find . -name "*.exe"`
	rm -fr `find . -name "*.ld"`
	rm -fr `find . -name "*.bin"`
