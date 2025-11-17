#include <stdio.h>

void incrementa (int n){
    n++;
    printf("la copia di x e' = %d \n", n);
    printf("l'indirizzo della copia di x e' = %p\n", (void*)&n);
}

int main() {
    int x = 5;
    incrementa(x);
    printf("il valore di x e' = %d\n", x);
    printf("il valore di x e' = %p\n", &x);
    return 0;
}