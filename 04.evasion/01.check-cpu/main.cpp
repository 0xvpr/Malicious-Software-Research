#include <windows.h>
#include <stdio.h>

[[nodiscard]]
bool check_cpu(void) {

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    if (systemInfo.dwNumberOfProcessors < 2) {
        return true;
    } 

    return false;
}

int main() {

    if (check_cpu()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
