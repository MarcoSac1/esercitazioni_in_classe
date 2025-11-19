// stampa dei numeri con un ciclo in un  range compreso tra 1 e 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(100);
    int num;
    int i ;

    for ( i = 0; i < 10; i++){
        int num =rand()%100 +1; //possibile fare rand()%(max-min+1)+0;
        printf("%d\n", num);
    }

    printf("\n");
    
    return 0;
}
