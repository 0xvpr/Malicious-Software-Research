#include <windows.h>
#include <stdio.h>

constexpr auto gigabyte = 1024u * 1024u * 1024u;

[[nodiscard]]
bool check_ram(void) {

    MEMORYSTATUSEX memoryStatusEx{.dwLength = sizeof(MEMORYSTATUSEX)};
    GlobalMemoryStatusEx(&memoryStatusEx);

    if (memoryStatusEx.ullTotalPhys / gigabyte < 2) {
        return true;
    } 

    return false;
}

int main() {

    if (check_ram()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
