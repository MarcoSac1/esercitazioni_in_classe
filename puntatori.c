#include <stdio.h>

int main() {
    int x;
    int *p=&x;


    printf("%p\n", (void*)&x);
    printf("%p", (void*)p);

    return 0;
}