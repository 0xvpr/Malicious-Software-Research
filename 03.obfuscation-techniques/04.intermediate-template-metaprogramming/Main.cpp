/**
 * Creator:    VPR
 * Created:    February 20th, 2021
 * Updated:    February 20th, 2021
 *
 * Disclaimer:
 *     This program was designed as a proof-of-concept. It doesn't do anything
 *     malicious and it is not intended to do so. Don't try to use it for any
 *     malicious or illegal activity.
**/

#include <stdio.h>
#include <malloc.h>

#define OBF(string) []() -> char* {                                     \
    constexpr auto s = Obfuscated<sizeof(string)/sizeof(char)>(string); \
    return s.Data();                                                    \
}()

template <int size>
struct Obfuscated {
private:
    char data[size];
    unsigned char key[size];
public:
    constexpr Obfuscated<size>(const char* text)
        : data()
        , key()
    {
        for (int i = 0; i < size; i++) {
            key[i] = __TIME__[i % sizeof(__TIME__)];
        }
        for (int i = 0; i < size; i++) {
            data[i] = text[i] ^ key[i % sizeof(key)];
        }
    }
    char* Data() const {
        char* tmp = (char *)malloc(size * sizeof(char));
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i] ^ key[i % sizeof(key)];
        }
        return tmp;
    }
};

int main() {

    void* tmp;
    printf("De-obfuscated:\t%s\n", (char *)(tmp = OBF("Testing")));
    free(tmp);

    return 0; 
}
