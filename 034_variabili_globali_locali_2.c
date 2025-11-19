// crea un programma dove la funzione  esegue il quadrato di n
#include <stdio.h>

int quadrato(int n){
    n=n*n;
    printf("il numovo valore di n e': %d\n", n);
    return n; // per farci ritornare n dopo l'incremento nel main
}

int main() {
    int k=0;
    printf("inserisci un numero: ");
    scanf("%d", &k);
    k=quadrato(k);
    printf("il valore n e' ancora %d\n", k);
    return 0;
}
