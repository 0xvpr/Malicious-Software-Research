#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#define BUFFER 0x00001000

#ifndef SOCKADDR_IN
typedef struct sockaddr_in(SOCKADDR_IN);
#endif

int main(void)
{
    int         result;
    WSADATA     WSAData;
    SOCKADDR_IN server_addr;
    SOCKET      server_socket;
    char        send_buffer[BUFFER];
    char        recv_buffer[BUFFER];

    // Declare version & initialize WSAData
    if ((result = WSAStartup(MAKEWORD(2, 2), &WSAData)) != EXIT_SUCCESS)
    {
        fprintf(stderr, "Failed with error code %d: Initialization failed.\n", result);
    }

    // Create client socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(8889);
    server_addr.sin_addr.s_addr = inet_addr("198.186.1.2");

    // Connect to server
    connect(server_socket, (SOCKADDR *)&server_addr, sizeof(server_addr));

    // Receive from the server
    recv(server_socket, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send data to server
    snprintf(send_buffer, sizeof(send_buffer), "Answer.\n");
    send(server_socket, send_buffer, sizeof(recv_buffer), 0);

    // Cleanup
    closesocket(server_socket);
    WSACleanup();

    return 0;
}
