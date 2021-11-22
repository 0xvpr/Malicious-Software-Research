#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>

#ifndef BUFSIZ
#define BUFSIZ 8192
#endif

#define DEBUG 1

int main() { 
    WSADATA     wsaData;
    WORD        wVersionRequired;
    SOCKADDR_IN server_addr;
    SOCKET      server;
    CHAR        recv_buffer[BUFSIZ];
    BOOL        rv;
  
    // Request the WinSock2 API
    wVersionRequired = MAKEWORD(2, 2);
    if ((rv = WSAStartup(wVersionRequired, &wsaData)) != EXIT_SUCCESS) {
        exit(0);
    }

    // Setup server address
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port        = htons(8080);
    server_addr.sin_family      = AF_INET;
  
    // Connect to the server
    server = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(server, (SOCKADDR *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        closesocket(server);
        WSACleanup();
        return -1;
    } else {
        std::cout << "[!] Connection Established.\n";
    }

  
    // Listen for commands from the server
    memset(recv_buffer, 0, sizeof(recv_buffer));
    while ((rv = recv(server, recv_buffer, BUFSIZ, 0))) {
        std::cout << "[+] Command received: " << recv_buffer << "\n";
        
        // Handle commands
        if (!strncmp(recv_buffer, "whoami", 6))
        {
            std::cout << "[!] Executing whoami...\n";
        }
        else if (!strncmp(recv_buffer, "shutdown", 8))
        {
            std::cout << "[!] Shutting down...\n";
            break;
        }

        // Reset the receive buffer
        memset(recv_buffer, 0, sizeof(recv_buffer));
        Sleep(100);
    }
    
    // Final Cleanup
    closesocket(server);
    WSACleanup();
    return 0;
}
