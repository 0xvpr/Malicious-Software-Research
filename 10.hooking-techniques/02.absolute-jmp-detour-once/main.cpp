#include <errhandlingapi.h>
#include <memoryapi.h>

#include <stdint.h>
#include <stdio.h>

constexpr size_t absolute_jmp_rax_size = 12;

class Hook {
public:
    Hook(auto&& original_addr_)
        : original_addr( (void *)original_addr_ )
        , original_bytes{ 0 }
        , detour_addr( nullptr )
        , is_hooked(false)
        , zero_byte(0xCC)
    {
        pHook = this;
        memcpy(original_bytes, original_addr, absolute_jmp_rax_size);
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

        VirtualProtect(detour_addr, 1, PAGE_EXECUTE_READWRITE, &dwProtect);
        zero_byte ^= *(uint8_t *)detour_addr;
        *(uint8_t *)detour_addr ^= zero_byte;
        zero_byte ^= *(uint8_t *)detour_addr;
        VirtualProtect(detour_addr, 1, dwProtect, &dwProtect);
    }

    void once(auto&& funcptr) {
        if (is_hooked) {
            return;
        }

        detour_addr = (void *)(+funcptr);
        swap_zero_byte();

        DWORD dwProtect = 0;
        VirtualProtect(original_addr, absolute_jmp_rax_size, PAGE_EXECUTE_READWRITE, &dwProtect);

        bool little_endian = ((uint32_t)0x12345678 & 0xFF) == 0x78;

        *(uint16_t *)original_addr =
            little_endian ? 0xB848 : 0x48B8;
        *(uintptr_t *)(((uintptr_t)(original_addr)+2)) =
            (uintptr_t)detour_addr;
        *(uint16_t *)((uintptr_t)original_addr + 10) =
            little_endian ? 0xE0FF : 0xFFE0;

        VirtualProtect(original_addr, absolute_jmp_rax_size, dwProtect, &dwProtect);

        is_hooked = true;
    }
    void restore() {
        if (!is_hooked) {
            return;
        }

        DWORD dwProtect = 0;

        VirtualProtect(original_addr, absolute_jmp_rax_size, PAGE_EXECUTE_READWRITE, &dwProtect);
        memcpy(original_addr, original_bytes, absolute_jmp_rax_size);
        VirtualProtect(original_addr, absolute_jmp_rax_size, dwProtect, &dwProtect);

        detour_addr = nullptr;
        is_hooked = false;
    }

    static Hook*    pHook;
private:
    void*           original_addr;
    uint8_t         original_bytes[absolute_jmp_rax_size];
    void*           detour_addr;
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
