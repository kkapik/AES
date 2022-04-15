#ifndef AES_MAIN
#define AES_MAIN

#include "aes.h"
#include "stdio.h"

int main() {
    struct AES aes;
    fread(aes.key, 4, 4, stdin); // 4*4 bytes
    while(!feof(stdin)) {
        fread(aes.state, 4, 4, stdin);
        if(!feof(stdin)) {
            encrypt(&aes);
            fwrite(aes.state, 4, 4, stdout);
        }
    }
    return 0;
}

#endif // AES_MAIN
