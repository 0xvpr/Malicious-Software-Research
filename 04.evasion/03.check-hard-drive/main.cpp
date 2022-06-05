#include <windows.h>
#include <stdio.h>

constexpr auto gigabyte = 1024u * 1024u * 1024u;

[[nodiscard]]
bool check_hard_drive(void) {

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

    dwDiskSize = diskGeometry.Cylinders.QuadPart * diskGeometry.TracksPerCylinder
        * diskGeometry.SectorsPerTrack * diskGeometry.BytesPerSector / gigabyte;

    if (dwDiskSize < 100) {
        return true;
    } 

    return false;
}

int main() {

    if (check_hard_drive()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
