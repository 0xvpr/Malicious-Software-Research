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

int check_hard_drive(void)
{
    DISK_GEOMETRY diskGeometry;
    DWORD dwBytesReturned;
    DWORD dwDiskSize;

    HANDLE hDevice = CreateFileA(
        "\\\\.\\PhysicalDrive0",
        0,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    DeviceIoControl(
        hDevice,
        IOCTL_DISK_GET_DRIVE_GEOMETRY,
        NULL,
        0,
        &diskGeometry,
        sizeof(diskGeometry),
        &dwBytesReturned,
        NULL
    );

    dwDiskSize = ((diskGeometry.Cylinders.QuadPart) * (diskGeometry.TracksPerCylinder)
        * (diskGeometry.SectorsPerTrack) * (diskGeometry.BytesPerSector)) / gigabyte;

    if (dwDiskSize < 100)
    {
        return EXIT_FAILURE;
    } 

    return EXIT_SUCCESS;
}

int main(void)
{
    return check_hard_drive();
}
