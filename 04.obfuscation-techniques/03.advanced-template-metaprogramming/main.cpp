/**
 * Creator:     VPR
 * Created:     March 21st, 2025
 * Updated:     March 21st, 2025
 *
 * Description: C++20 and onwards obfuscator_t PoC for compile-time obfuscated strings.
 *              - Works on g++ using -Ofast/O3 optimization.
 *              - Does not use any stdlibc++ objects for linking.
 *
 * Disclaimer:  This program was designed as a proof-of-concept. It doesn't do
 *              anything malicious and it is not intended to do so. Don't try
 *              to use it for any malicious or illegal activity.
**/

#include <cstddef>
#include <cstdio>
#include <array>

template <std::size_t size>
struct obfuscator_t {
    consteval obfuscator_t(const char (&string)[size])
    : key{ __TIME__ }
    , data{
        [=,this]() -> auto {
            std::array<char, size+1> tmp{};
            for (std::size_t i = 0; i < size; i++) {
                tmp[i] = string[i] ^ key[i % sizeof(key)];
            }
            return tmp;
        }()
    }
    , data_unenc{}
    {}

    constexpr ~obfuscator_t() {
        for (std::size_t i = 0; i < size; ++i) {
            data_unenc[i] = 0;
        }
    }
    constexpr auto deobfuscate() const {
        for (std::size_t i = 0; i < size; ++i) {
            data_unenc[i] = data[i] ^ key[i % sizeof(key)];
        }

        return data_unenc;
    }
    volatile const char* operator () () const {
        return deobfuscate();
    }

    const std::array<char, sizeof(__TIME__)> key;
    const std::array<char, size+1> data;
    mutable volatile char data_unenc[size+1];
};

volatile const char* tmp;

int main() {
    fprintf(stdout, "Obfuscated text: %s\n", obfuscator_t("Obfuscator-version-3")() ); // invisible to grep -i Obfuscator-version-3

    return 0; 
}
