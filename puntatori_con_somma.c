//assega i puntatori ad una funzione soma che ci somma i puntatori
#include <stdio.h>

void somma (int *a, int *b, int *risultato){
    *risultato= *a+*b;

    printf("\n l'indirizzo di a nella funzione e'; %p", (void*)a);
    printf("\n l'indirizzo di b nella funzione e'; %p", (void*)b);
    printf("\n l'indirizzo del risultato e' -> %p \n", (void*)&risultato);

}


int main() {
    int x =5;
    int y= 10;
    int risultato =0;

    somma(&x, &y ,&risultato);
    printf("\n l'indirizzo di a nella funzione e'; %p", (void*)&x);
    printf("\n l'indirizzo di b nella funzione e'; %p", (void*)&y);
    printf("\nil risultato della somma e': %d\n", risultato);
    return 0;
}