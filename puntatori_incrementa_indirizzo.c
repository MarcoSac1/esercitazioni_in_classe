#include <stdio.h>

void incrementa(int*n){
    *n=*n+1;
    printf("n contiene l'indirizzo di x %p\n", (void*)n);
    printf("n contiene l'indirizzo di n e'%p\n", (void*)&n);

}

int main() {
    int x=5;
    incrementa(&x);
    printf("l'indirizzo e diventato -> %d \n", x);
    printf("l'indirizzo di x e' -> %p \n", (void*)&x);
    
    return 0;
}