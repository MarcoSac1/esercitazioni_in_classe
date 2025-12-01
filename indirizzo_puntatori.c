#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int main(void) {
    int a = 0xF4359403;
    uintptr_t addr = (uintptr_t)&a;
    unsigned char *p = (unsigned char *)&a; // o (unsigned char*)addr

    printf("Indirizzo (uintptr): 0x%" PRIxPTR "\n", addr);
    printf("Indirizzo (pointer): %p\n", (void*)&a);
    printf("Intero a = 0x%x\n", a);

    printf("Byte di a: ");
    for (size_t i = 0; i < sizeof a; ++i)
        printf("%02x ", p[i]);
    printf("\n");

    printf("Primo byte (unsigned): %u\n", (unsigned int)p[0]);
    return 0;
}
