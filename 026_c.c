// creare un array di numeri casuali  inserendo la variabile time
// (random)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

int main() {
    int i;
    int array [DIM];
    srand(time(NULL));
    int length = sizeof(array) / sizeof (array[0]);

    for ( i = 0; i < length; i++){
        printf("%d---valori dello stack---%d\n",i+1 , array[i]);
    }

    for ( i = 0; i < length; i++){
        array[i]= rand();
        printf("%d---stampo il seed dei numeri randomici---%d\n",i+1 , array[i]);
    }
    
    
    return 0;
}