#include <sys/socket.h> // socket, bind, send, recv
#include <arpa/inet.h>  // inet_addr, htons, sockaddr_in
#include <string.h>     // memset
#include <stdio.h>      // snprintf

#define BUFFER 0x00001000

#ifndef SOCKADDR_IN
typedef struct sockaddr_in SOCKADDR_IN;
#endif

int main(void)
{
    int         server_socket;        // Used for creating socket.
    int         client_socket;        // Used for accepting connection.
    SOCKADDR_IN server_addr;          // Hosted server struct
    char        send_buffer[BUFFER];  // Outbound buffer of 4 Kilobytes
    char        recv_buffer[BUFFER];  // Inbound buffer of 4 Kilobytes

    // Setup server address
    server_addr.sin_family      = AF_INET;                  // IPv4
    server_addr.sin_port        = htons(8889);              // Port
    server_addr.sin_addr.s_addr = inet_addr("198.186.1.2"); // Address

    // Creates a TCP Socket 
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Binds the server socket
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);
    printf("Listening...\n");

    // Establish client socket connection
    client_socket = accept(server_socket, NULL, NULL);
    printf("Connection established.\n");

    // Send data
    memset(send_buffer, 0, sizeof(send_buffer));
    snprintf(send_buffer, sizeof(send_buffer), "Call...\n");
    send(client_socket, send_buffer, sizeof(send_buffer), 0);

    // Receive data
    memset(recv_buffer, 0, sizeof(recv_buffer));
    recv(client_socket, recv_buffer, sizeof(recv_buffer), 0);
    printf("%s", recv_buffer);

    return 0;
}
