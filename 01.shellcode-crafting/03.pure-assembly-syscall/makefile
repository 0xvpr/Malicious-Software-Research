PROJECT = syscall

ASM     = nasm
ASFLAGS = -f win64

LD      = x86_64-w64-mingw32-ld
LDFLAGS = -s --entry=entry --section-alignment=16 --file-alignment=16

all: syscall.exe

syscall.exe: src/syscall.asm bin build
	$(ASM) $(ASFLAGS) src/syscall.asm -o build/syscall.o
	$(LD) build/syscall.o $(LDFLAGS) -o bin/$@

bin:
	mkdir -p $@

build:
	mkdir -p $@

clean:
	rm -fr ./bin
	rm -fr ./build
