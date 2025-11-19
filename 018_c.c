//scrivi un programma con il while che se il voto e fuori dal intervallo 0 -10 fai ri inserire al utente un voto compreso tra 0 e 10
#include <stdio.h>

int main() {
    int voto;
    printf("inserisci un voto tra 0 e 10 \n");
    scanf("%d", &voto);
    int i=0;
    while (i > 0|| i < 10)
    {
        i++;
        if (voto <=10 & voto >= 6){
            printf("sei stato promoso il tuo voto e' %d\n", voto);

        }else{
            printf("voto non valido inserisci un voto tra 0 e 10 \n");
            scanf("%d", &voto);
        }
        
    }
    
    return 0;
}


