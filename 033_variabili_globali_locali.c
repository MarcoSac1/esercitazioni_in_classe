#include <stdio.h>
/*
void incrementa(int n){
    n=n+1;
    printf("il numovo valore di n e': %d\n", n);
}

int main() {
    int k=0;

    printf("inserisci un numero: ");
    scanf("%d", &k);
    incrementa(k);
    printf("il valore n e' ancora %d\n", k); 
    return 0 --> qui k ritorna ad essere 5 perche il n e una variabile locale di void incrementa
}
*/

int incrementa(int n){
    n=n+1;
    printf("il numovo valore di n e': %d\n", n);
    return n; // per farci ritornare n dopo l'incremento nel main
}

int main() {
    int k=0;
    printf("inserisci un numero: ");
    scanf("%d", &k);
    k=incrementa(k);
    printf("il valore n e' ancora %d\n", k);
    return 0;
}

