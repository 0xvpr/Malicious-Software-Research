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

int check_cpu(void)
{
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    if (systemInfo.dwNumberOfProcessors < 2)
    {
        return EXIT_FAILURE;
    } 

    return EXIT_SUCCESS;
}

int main(void)
{
    return check_cpu();
}