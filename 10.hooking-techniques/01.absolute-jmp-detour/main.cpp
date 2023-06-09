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
    {
        memcpy(original_bytes, original_addr, absolute_jmp_rax_size);
    }
    ~Hook()
    {
        restore();
    }

    void detour(auto&& funcptr) {
        if (is_hooked) {
            return;
        }

        detour_addr = (void *)(+funcptr);

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
private:
    void*   original_addr;
    uint8_t original_bytes[absolute_jmp_rax_size];
    void*   detour_addr;
    bool    is_hooked;
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
