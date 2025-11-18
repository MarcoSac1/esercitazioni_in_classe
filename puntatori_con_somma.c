//assega i puntatori ad una funzione soma che ci somma i puntatori
#include <stdio.h>

void somma (int *a, int *b, int *risultato){
    *risultato= *a+*b;

    printf("l'indirizzo del risultato e' -> %p \n", (void*)&risultato);

}


int main() {
    int x =5;
    int y= 10;
    int risultato =0;

    

    somma(&x, &y ,&risultato);

    printf("il risultato della somma e': %d\n", risultato);
    return 0;
}