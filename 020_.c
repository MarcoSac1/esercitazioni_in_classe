//crea un programma che stampa un menu dove 1 fa la somma, 2 fa la differenza, 3 esce dal programma
#include <stdio.h>
int main() {

    int a=0;
    int b=0;
    int scelta=0;
    int somma;
    int differenza;
    int moltiplicazione;
    int divisione;

    do{
        printf("\n----menu'----\n \n 1. somma \n 2. Differenza \n 3. moltiplicazione \n 4. divisione\n 5. Esci \n \n");
        printf("scegli un operazione da fare ^\n");
        scanf("%d", &scelta);
        printf("la tua scelta e' %d \n", scelta);
        switch(scelta){

            case 1:
            printf("\nInserisci il primo valore della somma \n");
            scanf("%d", &a);
            printf("\nInserisci il secondo valore della somma \n");
            scanf("%d", &b);
            somma=a+b;
            printf("\nLa somma dei due numeri e': %d\n", somma);
            break;
            
            case 2:
            printf("Inserisci il primo valore della sottrazione \n");
            scanf("%d", &a);
            printf("Inserisci il secondo valore della sottrazione \n");
            scanf("%d", &b);
            differenza=a-b;
            printf("\nLa differenza dei due numeri e': %d\n",differenza);
            break;

            case 3:
            printf("Inserisci il primo valore della moltiplicazione \n");
            scanf("%d", &a);
            printf("Inserisci il secondo valore della moltiplicazione \n");
            scanf("%d", &b);
            moltiplicazione=a*b;
            printf("\nLa moltiplicazione dei due numeri e': %d\n",moltiplicazione);
            break;

            case 4:
            printf("Inserisci il primo valore della divisione \n");
            scanf("%d", &a);
            printf("Inserisci il secondo valore della divisione \n");
            scanf("%d", &b);
            divisione=a/b;
            printf("\nLa divisione dei due numeri e': %d\n",divisione);
            break;

            default:
            printf("scelta non valida!");
    }
       
} while (scelta!=0);
}
