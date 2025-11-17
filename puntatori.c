#include <stdio.h>

int main() {
    int x;
    int *p=&x;

    printf("%p\n", (void*)&x);
    // sono due modi che mi fanno ottenere lo stesso risultato
    printf("%p", (void*)p);

    return 0;
}