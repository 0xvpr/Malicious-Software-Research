/**
 * Creator:    VPR
 * Created:    November 21, 2021
 * Updated:    November 22, 2021
 *
 * Disclaimer:
 *     This program was designed as a proof-of-concept. It doesn't do anything
 *     malicious and it is not intended to do so. Don't try to use it for any
 *     malicious or illegal activity.
**/

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>
#include <stdio.h>

#define BUFFER 0x00001000

#ifndef SOCKADDR_IN
typedef struct sockaddr_in SOCKADDR_IN;
#endif

int main(void)
{
    BOOL        rv;                   // Return value of WSAStartup
    WSADATA     WSAData;              // Windows Socket Application struct
    WORD        wVersionRequested;    // Winsock version
    SOCKADDR_IN server_addr;          // Targeted server struct
    SOCKET      server_socket;        // Socket
    char        send_buffer[BUFFER];  // Outbound buffer of 4 Kilobytes
    char        recv_buffer[BUFFER];  // Inbound buffer of 4 Kilobytes

    // Declare version & initialize WSAData
    wVersionRequested = MAKEWORD(2, 2); // Winsock version 2
    if ((rv = WSAStartup(wVersionRequested, &WSAData)) != EXIT_SUCCESS)
    {
        fprintf(stderr, "Initialization failed with error code %d.\n", rv);
    }

    // Create client socket
    server_addr.sin_family      = AF_INET;                  // IPv4
    server_addr.sin_port        = htons(8889);              // Port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Address

    // Create a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Connect to server
    if (connect(server_socket, (SOCKADDR *)&server_addr, sizeof(server_addr)) != 0)
    {
        return 1;
    }

    // Receive data from the server
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(server_socket, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    // Send data to server
    memset(send_buffer, 0, sizeof(send_buffer));
    snprintf(send_buffer, sizeof(send_buffer), "Answer.\n");
    send(server_socket, send_buffer, sizeof(send_buffer), 0);

    // Cleanup
    closesocket(server_socket);
    WSACleanup();

    return 0;
}
