#include "definitions.hpp"
#include <inttypes.h>

#define OBF(string) [&]() -> char* {                                    \
    constexpr auto s = Obfuscated<sizeof(string)/sizeof(char)>(string); \
    return s.Data(malloc);                                              \
}()
    
// kernel32.dll typing
typedef HMODULE (WINAPI * loadlibrary_t)(LPCSTR);

// msvcrt.dll typing
typedef void* (WINAPI * malloc_t)(size_t size);
typedef void* (WINAPI * free_t)(void* lpMemory);
typedef int (WINAPI * printf_t)(const char* format, ...);

template <int size>
struct [[nodiscard]] Obfuscated
{
private:
    unsigned char data[size];
    unsigned char key[size];
    unsigned char salt = __TIME__[1] + __TIME__[2] + __TIME__[3];
public:
    constexpr Obfuscated<size>(const char* text)
        : data()
        , key()
    {
        for (unsigned i = 0; i < size; i++) {
            key[i] = (unsigned char)(salt ^ __TIME__[i % sizeof(__TIME__)]);
        }
        for (unsigned i = 0; i < size; i++) {
            data[i] = 0xFF & (text[i] ^ key[i % sizeof(key)]);
        }
    }

    char* Data(unsigned long long malloc) const
    {
        unsigned char* tmp = (unsigned char *)((malloc_t)malloc)(size * sizeof(char));
        for (unsigned i = 0; i < size; i++)
        {
            tmp[i] = 0xFF & (data[i] ^ key[i % sizeof(key)]);
        }

        return (char *)tmp;
    }
};

void write_hello(void)
{
    // Dlls to dynamically load during runtime
    UINT64 kernel32dll;
    UINT64 msvcrtdll;

    // Symbols to dynamically resolve from dll during runtime
    UINT64 LoadLibraryAFunc;
    UINT64 wprintfFunc;
    UINT64 malloc;
    UINT64 free;

    // kernel32.dll imports
    kernel32dll = GetKernel32();
    char szLoadLibraryA[] = { 'L', 'o', 'a', 'd', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 'A', 0 };
    LoadLibraryAFunc = GetSymbolAddress((HANDLE)kernel32dll, szLoadLibraryA);

    // msvcrt.dll imports
    char szMsvcrt[] = { 'm', 's', 'v', 'c', 'r', 't', '.', 'd', 'l', 'l', 0 };
    msvcrtdll = (UINT64) ((loadlibrary_t)LoadLibraryAFunc)(szMsvcrt);

    // Importing malloc for obfuscator
    CHAR szMalloc[] = { 'm', 'a', 'l', 'l', 'o', 'c', 0 };
    malloc = GetSymbolAddress((HANDLE)msvcrtdll, szMalloc);

    // Importing free for obfuscator cleanup
    CHAR szFree[] = { 'f', 'r', 'e', 'e', 0 };
    free = GetSymbolAddress((HANDLE)msvcrtdll, szFree);

    // Function to test
    CHAR szPrintf[] = { 'p', 'r', 'i', 'n', 't', 'f', 0 };
    wprintfFunc = GetSymbolAddress((HANDLE)msvcrtdll, szPrintf);

    // Advanced string obfuscation tech
    auto szMessage = OBF("None of this string will be found at runtime :)\n");
    ((printf_t)wprintfFunc)(szMessage);
    ((free_t)free)(szMessage);
}
