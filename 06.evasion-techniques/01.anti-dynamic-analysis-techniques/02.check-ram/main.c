/**
 * Created by:      VPR
 * Created:         ???
 * 
 * Updated by:      VPR
 * Updated:         February 3rd, 2024
 * 
 * Description:     Detecting virtualized environment:
 *                  Typical user workstation has a processor with at least 2 cores, a minimum of  
 *                  2 GB of RAM and a 100 GB hard drive. We can verify if the environment our  
 *                  malicious application is being executed in is a subject to these constrains:
 * 
 * Credit to 0xPat - https://0xpat.github.io/Malware_development_part_2
**/

#include <windows.h>
#include <stdint.h>

static const uint32_t gigabyte = 1024u * 1024u * 1024u;

int check_ram(void)
{
    MEMORYSTATUSEX memoryStatusEx = { .dwLength = sizeof(MEMORYSTATUSEX) };
    GlobalMemoryStatusEx(&memoryStatusEx);

    if (memoryStatusEx.ullTotalPhys / gigabyte < 2)
    {
        return EXIT_FAILURE;
    } 

    return EXIT_SUCCESS;
}

int main(void)
{
    return check_ram();
}
