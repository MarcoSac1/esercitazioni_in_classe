// crea una funzione dove passando un valore invochiamo la funzione

#include <stdio.h>

void incrementa(int n){
    n=n+1;
    printf("il nuovo valore e' %d", n);
}


int main() {
    int k;
    printf("inserisci il valore da incrementare!");
    scanf("%d", &k);
    incrementa(k);
    return 0;
}