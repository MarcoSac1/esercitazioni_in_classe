#include <stdio.h>

void somma(int *a, int *b, int *risultato){
    *risultato =*a+ *b;

    printf("\n l'indirizzo di a nella funzione e'; %p", (void*)&a);
    printf("\n l'indirizzo di b nella funzione e'; %p", (void*)&b);
    printf("\n l'indirizzo del risultato nella funzione e'; %p", (void*)&risultato);


}

int main() {
    
    int a;
    int b;
    int risultato;

    printf("inserisci il valore di a-->");
    scanf("%d",&a);
    printf("inserisci il valore di b-->");
    scanf("%d",&b);

    printf("\n l'indirizzo di a nella funzione e'; %p", (void*)&a);
    printf("\n l'indirizzo di b nella funzione e'; %p", (void*)&b);
    printf("\n l'indirizzo del risultato nella funzione e'; %p\n", (void*)&risultato);
    somma(&a, &b ,&risultato);

    printf("la somma e':%d\n", risultato);
    return 0;
}