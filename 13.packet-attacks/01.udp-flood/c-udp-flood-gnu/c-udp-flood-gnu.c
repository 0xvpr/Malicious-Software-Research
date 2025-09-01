// Created by:  VPR
// Created:     September 1st, 2025

// Updated:     VPR
// Updated:     September 1st, 2025

// Description: A simple udp socket script for sending udp packets to a target.
//              I don't feel like making it pretty.

// Usage:       usage: python-udp-flood.py [N_PACKETS]

// License:     MIT (c) VPR, VPR-labs, et. al, 2025

#include <stdint.h>
#include <stdio.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
    char* host = "127.0.0.1";
    uint16_t port = 8000;
    size_t n_packets = 1000;

    if (argc == 2) { sscanf(argv[1], "%lu", &n_packets); }

    struct sockaddr_in target = { 0 };
    target.sin_addr.s_addr = inet_addr(host);
    target.sin_port = htons(port);
    target.sin_family = AF_INET;
    
    uint8_t payload[32] = { 0 };
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 
    for (size_t i = 0; i < n_packets; ++i)
    {
        sendto(s, payload, sizeof(payload), 0, (struct sockaddr *)&target, sizeof(target));
    }

    return 0;
}
