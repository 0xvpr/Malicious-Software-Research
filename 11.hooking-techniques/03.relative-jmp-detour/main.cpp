/**
 * Creator:         VPR
 * Created:         April 1st, 2024
 *
 * Updater:         VPR
 * Updated:         April 1st, 2024
 *
 * Description:     This example aims to provide an example of how to  
 *                  leverage C++20 to perform function hooking via  
 *                  detours to spontaneous functions.
 *
 *                  (This is intended for Intel CPU - 64-bit Windows machines)
**/

#include <memoryapi.h>

#include <stdint.h>
#include <stdio.h>

/** DEFINITIONS **/
typedef struct __attribute__((packed)) _AsmBlock {
    uint8_t    rel_jmp;
    int32_t    address;
} AsmBlock;

/** CONSTANTS **/
constexpr uint8_t rel_jmp = 0xE9;
constexpr size_t rel_jmp_size = sizeof(AsmBlock);

class Hook {
public:
    constexpr Hook(auto&& original_addr_)  
        : original_addr( (void *)original_addr_ )
        , restore_block( *(AsmBlock *)original_addr_)
        , detour_block( (AsmBlock &)original_addr_)
        , detour_func( nullptr )
        , is_hooked(false) 
    { }
    ~Hook()
    {
        restore();
    }

    void detour(auto&& funcptr) {
        if (is_hooked) {
            return;
        }


        detour_func = (void *)(+funcptr);
        uint64_t relative_address = (uintptr_t)detour_func - (uintptr_t)original_addr - 5;
        if (relative_address < 0x100000000) {
            return; // 32bit integer overflow
        }

        DWORD dwProtect = 0;
        VirtualProtect(original_addr, rel_jmp_size, PAGE_EXECUTE_READWRITE, &dwProtect);
        detour_block.rel_jmp = rel_jmp;
        detour_block.address = (int32_t)(relative_address);
        VirtualProtect(original_addr, rel_jmp_size, dwProtect, &dwProtect);

        is_hooked = true;
    }
    void restore() {
        if (!is_hooked) {
            return;
        }

        DWORD dwProtect = 0;

        VirtualProtect(original_addr, rel_jmp_size, PAGE_EXECUTE_READWRITE, &dwProtect);
        detour_block = restore_block;
        VirtualProtect(original_addr, rel_jmp_size, dwProtect, &dwProtect);

        detour_func = nullptr;
        is_hooked = false;
    }
private:
    void*           original_addr;
    const AsmBlock  restore_block;
    AsmBlock&       detour_block;
    void*           detour_func;
    bool            is_hooked;
};

int main(void) {
    auto hook = Hook(scanf);
    hook.detour([](const char*, int* x_) -> void {
        puts("Detour\n");
        *x_ = 42069;
    });

    int x = 0;
    scanf("%d", &x);
    printf("x: %d\n", x);

    hook.restore();

    scanf("%d", &x);
    printf("x: %d\n", x);

    return 0;
}
