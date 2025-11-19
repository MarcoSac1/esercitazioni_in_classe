/*
#include <stdio.h>

int somma;
int mid;


int media( n ,a){

    somma = n + a;
    mid = somma/2;
    printf("la media dei due numeri e' %d\n ",mid);
    
    return mid;
}


int main() {

    int n = 0;
    int a = 0;

    printf("inserisci il primo numero ", n );
    scanf("%d",&n);
    
    printf("inserisci il secondo numero ", a );
    scanf("%d", &a);
    
    media(n, a);
    return 0;
}*/

#include <stdio.h>

float media(int n1, int n2){
    return (float)(n1+n2)/2;// (float) = casting server per forzare il tipo di risultato che ci ritorna
    
}

int main(){
    int a, b;
    printf("----calcolo media tra due numeri----\n");
    printf("inserisci il primo numero:");
    scanf("%d", &a);
    printf("inserisci il secondo numero:");
    scanf("%d", &b);
    float risultato = media(a,b);
    printf("La media e' = %.2f\n", risultato);

}