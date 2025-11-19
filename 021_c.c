#include <stdio.h>

    int somma(){
            int a, b;
            printf("\nInserisci il primo valore della somma \n");
            scanf("%d", &a);
            printf("\nInserisci il secondo valore della somma \n");
            scanf("%d", &b);
            return a+b;
    }

    int differenza(){
            int a,b;
            printf("Inserisci il primo valore della sottrazione \n");
            scanf("%d", &a);
            printf("Inserisci il secondo valore della sottrazione \n");
            scanf("%d", &b);
            return a-b;
    }

    int moltiplicazione(){
        int a, b;
            printf("Inserisci il primo valore della moltiplicazione \n");
            scanf("%d", &a);
            printf("Inserisci il secondo valore della moltiplicazione \n");
            scanf("%d", &b);
            return a*b;

    }

    int divisione(){
        int a,b;
            printf("Inserisci il primo valore della divisione \n");
            scanf("%d", &a);
            printf("Inserisci il secondo valore della divisione \n");
            scanf("%d", &b);
            return a/b;
    }

    int main() {

        int scelta=0;
        int risultato;

    do{

        printf("\n----menu'----\n \n 1. somma \n 2. Differenza \n 3. moltiplicazione \n 4. divisione\n 0. Esci \n \n");
        printf("scegli un operazione da fare ^\n");
        scanf("%d", &scelta);
        printf("la tua scelta e' > %d \n", scelta);
        switch(scelta){

            case  1:
            risultato= somma();
            printf("\nLa somma dei due numeri e': %d\n", risultato);
            break;

            case 2:
            risultato=differenza();
            printf("\nLa differenza dei due numeri e': %d\n",risultato);
            break;

            case 3:
            risultato=moltiplicazione();
            printf("\nLa moltiplicazione dei due numeri e': %d\n",risultato);
            break;

            case 4:
            risultato=divisione();
            printf("\nLa divisione dei due numeri e': %d\n",risultato);
            break;

        return 0;
    }
}while(scelta!=0);{
    printf("\n ciao a presto ! \n");
}
}