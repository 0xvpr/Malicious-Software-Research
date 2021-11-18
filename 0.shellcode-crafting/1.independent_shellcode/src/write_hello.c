#include "definitions.h"
#include <inttypes.h>
    
// kernel32.dll exports
typedef HMODULE(WINAPI* LOADLIBRARYA)(LPCSTR);
typedef BOOL(WINAPI* CLOSEHANDLE)(HANDLE);
typedef HANDLE(WINAPI* GETCURRENTPROCESS)(VOID);

// advapi32.dll exports
typedef BOOL(WINAPI* OPENPROCESSTOKEN)(HANDLE, DWORD, PHANDLE);
typedef BOOL(WINAPI* GETTOKENINFORMATION)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD);
typedef BOOL(WINAPI* LOOKUPPRIVILEGENAMEW)(LPCWSTR,  PLUID, LPWSTR, LPDWORD);

// msvcrt.dll exports
typedef int(WINAPI* WPRINTF)(const wchar_t* format, ...);
typedef void*(WINAPI* CALLOC)(size_t num, size_t size);

WCHAR message[] = { L'H', L'e', L'l', L'l', L'o', L'\n', 0 };

void write_hello(void)
{
    // Dlls to dynamically load during runtime
    UINT64 kernel32dll;
    UINT64 msvcrtdll;

    // Symbols to dynamically resolve from dll during runtime
    UINT64 LoadLibraryAFunc;
    UINT64 wprintfFunc;

    // kernel32.dll exports
    kernel32dll = GetKernel32();
    CHAR loadlibrarya_c[] = {'L', 'o', 'a', 'd', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 'A', 0};
    LoadLibraryAFunc = GetSymbolAddress((HANDLE)kernel32dll, loadlibrarya_c);

    // msvcrt.dll exports
    CHAR msvcrt_c[] = {'m', 's', 'v', 'c', 'r', 't', '.', 'd', 'l', 'l', 0};
    msvcrtdll = (UINT64) ((LOADLIBRARYA)LoadLibraryAFunc)(msvcrt_c);
    CHAR wprintf_c[] = {'w', 'p', 'r', 'i', 'n', 't', 'f', 0};
    wprintfFunc = GetSymbolAddress((HANDLE)msvcrtdll, wprintf_c);

    ((WPRINTF)wprintfFunc)(message);
}
