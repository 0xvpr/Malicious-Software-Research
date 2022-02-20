PROJECT := dropper

RC := x86_64-w64-mingw32-windres
CC := x86_64-w64-mingw32-gcc

all:
	$(RC) resources.rc -Ocoff resources.res
	$(CC) -std=c99 -o $(PROJECT).exe main.c resources.res

clean:
	rm $(PROJECT).exe
