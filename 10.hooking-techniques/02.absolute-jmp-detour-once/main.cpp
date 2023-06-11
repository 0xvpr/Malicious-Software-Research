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
typedef struct __attribute__((packed)) _AsmBlock {
    uint16_t   mov_rax;
    void*      address;
    uint16_t   jmp_rax;
} AsmBlock;

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
        , zero_byte(0xCC)
    {
        pHook = this;
        SetUnhandledExceptionFilter( [](EXCEPTION_POINTERS* exceptionInfo) -> LONG WINAPI {
            if (exceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT) {
                pHook->swap_zero_byte();
                pHook->restore();

                return EXCEPTION_CONTINUE_EXECUTION;
            };

            return EXCEPTION_CONTINUE_SEARCH;
        });
    }

    void swap_zero_byte() {
        DWORD dwProtect = 0;

        VirtualProtect(detour_func, 1, PAGE_EXECUTE_READWRITE, &dwProtect);
        zero_byte ^= *(uint8_t *)detour_func;
        *(uint8_t *)detour_func ^= zero_byte;
        zero_byte ^= *(uint8_t *)detour_func;
        VirtualProtect(detour_func, 1, dwProtect, &dwProtect);
    }

    void once(auto&& funcptr) {
        if (is_hooked) {
            return;
        }

        detour_func = (void *)(+funcptr);
        swap_zero_byte();

        DWORD dwProtect = 0;
        VirtualProtect(original_addr, absolute_jmp_rax_size, PAGE_EXECUTE_READWRITE, &dwProtect);
        detour_block.mov_rax = mov_rax_;
        detour_block.address = detour_func;
        detour_block.jmp_rax = jmp_rax_;
        VirtualProtect(original_addr, absolute_jmp_rax_size, dwProtect, &dwProtect);

        is_hooked = true;
    }
    void restore() {
        if (!is_hooked) {
            return;
        }

        DWORD dwProtect = 0;
        VirtualProtect(original_addr, absolute_jmp_rax_size, PAGE_EXECUTE_READWRITE, &dwProtect);
        detour_block = restore_block;
        VirtualProtect(original_addr, absolute_jmp_rax_size, dwProtect, &dwProtect);

        detour_func = nullptr;
        is_hooked = false;
    }
private:
    static Hook*    pHook;
    void*           original_addr;
    const AsmBlock  restore_block;
    AsmBlock&       detour_block;
    void*           detour_func;
    bool            is_hooked;
    uint8_t         zero_byte;
};

Hook* Hook::pHook = nullptr;

int main(void) {

    auto hook = Hook(scanf);
    hook.once([](const char*, int* x_) -> void {
        puts("Detour\n");
        *x_ = 42069;
    });

    int x = 0;
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &x);
        printf("x: %d\n", x);
    }

    return 0;
}
