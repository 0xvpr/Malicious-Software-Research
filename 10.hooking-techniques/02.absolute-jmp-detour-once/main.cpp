/**
 * Creator:         VPR
 * Created:         June 8th, 2023
 *
 * Updater:         VPR
 * Updated:         June 10th, 2023
 *
 * Description:     This example aims to provide an example of how to leverage
 *                  C++20 to perform function hooking via detours to spontaneous
 *                  functions. This version of the PoC utilizes Windows own
 *                  breakpoint API to restore original code at the initial execution.
 *
 *                  (This is intended for Intel CPU - 64-bit Windows machines)
**/

#include <errhandlingapi.h>
#include <memoryapi.h>

#include <stdint.h>
#include <stdio.h>

/** DEFINITIONS **/
typedef struct __attribute__((packed)) {
    uint16_t   mov_rax;
    void*      address;
    uint16_t   jmp_rax;
} AsmBlock ;

/** CONSTANTS **/
constexpr uint16_t mov_rax_ = ((uint16_t)0x1234 & 0xFF) == 0x34 ? 0xB848 : 0x48B8;
constexpr uint16_t jmp_rax_ = ((uint16_t)0x1234 & 0xFF) == 0x34 ? 0xE0FF : 0xFFE0;
constexpr size_t absolute_jmp_rax_size = sizeof(AsmBlock);

class Hook {
public:
    constexpr Hook(auto&& original_addr_)
        : original_addr( (void *)original_addr_ )
        , restore_block( *(AsmBlock *)original_addr_)
        , detour_block( (AsmBlock &)original_addr_)
        , detour_func( nullptr )
        , is_hooked(false) 
    {
        hook_ptr = this;
    }

    void detour(auto&& funcptr) {
        if (is_hooked) {
            return;
        }

        detour_func = (void *)(+funcptr);

        DWORD dwProtect = 0;
        VirtualProtect(original_addr, absolute_jmp_rax_size, PAGE_EXECUTE_READWRITE, &dwProtect);
        detour_block.mov_rax = mov_rax_;
        detour_block.address = detour_func;
        detour_block.jmp_rax = jmp_rax_;
        VirtualProtect(original_addr, absolute_jmp_rax_size, dwProtect, &dwProtect);

        is_hooked = true;
    }
    static void restore() {
        if (!hook_ptr || !hook_ptr->is_hooked) {
            return;
        }

        DWORD dwProtect = 0;
        VirtualProtect(hook_ptr->original_addr, absolute_jmp_rax_size, PAGE_EXECUTE_READWRITE, &dwProtect);
        hook_ptr->detour_block = hook_ptr->restore_block;
        VirtualProtect(hook_ptr->original_addr, absolute_jmp_rax_size, dwProtect, &dwProtect);

        hook_ptr->detour_func = nullptr;
        hook_ptr->is_hooked = false;
    }
private:
    void*           original_addr;
    const AsmBlock  restore_block;
    AsmBlock&       detour_block;
    void*           detour_func;
    bool            is_hooked;
public:
    static          Hook* hook_ptr;
};

int main(void) {
    auto hook = Hook(scanf);
    hook.detour([](char*, int* x) -> void {
        puts("Detour\n");
        *x = 42069;

        Hook::hook_ptr->restore();
    });

    int x = 0;
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &x);
        printf("x: %d\n", x);
    }

    return 0;
}
