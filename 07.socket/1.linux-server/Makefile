all:
	gcc server.c -o server
	x86_64-w64-mingw32-gcc client.c -o client.exe -lws2_32

clean:
	rm server client.exe
