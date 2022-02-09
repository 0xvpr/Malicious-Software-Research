/**
 * Creator:    VPR
 * Created:    February 9th, 2021
 * Updated:    February 9th, 2021
 *
 * Disclaimer:
 *     This program was designed as a proof-of-concept. It doesn't do anything
 *     malicious and it is not intended to do so. Don't try to use it for any
 *     malicious or illegal activity.
**/

#include <stdlib.h>
#include <stdio.h>

template <int N>
struct Obfuscator {
    char data[N+1]{0};
    constexpr Obfuscator<N>(const char* string) {
        for (int i = 0; i < N; i++) {
            data[i] = string[i] ^ 0x11;
        }
    }
    char* Deobfuscate() const {
        char* tmp = (char *)malloc(N * sizeof(char));
        for (int i = 0; i < N; i++) {
            tmp[i] = data[i] ^ 0x11;
        }
        return tmp;
    }
};

int main() {

    constexpr Obfuscator<7> obfuscated = Obfuscator<7>("Testing");
    printf("Obfuscated:\t%s\nDe-obfuscated:\t%s\n", obfuscated.data, obfuscated.Deobfuscate());

    return 0; 
}
