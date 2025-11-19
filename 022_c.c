//sichiara un array di 10 elementi int e verificare tutti i valori che contengono 
#include <stdio.h>

int main() {
    int array[10];
    int i;
    int length =sizeof(array)/sizeof(array[0]);


    for (int i = 0; i < length; i++)
    {
        printf(" %d - %d\n", i, array[i]);
    }
    
    /*printf("%d\n", array[0]);
    printf("%d\n", array[1]);
    printf("%d\n", array[2]);
    printf("%d\n", array[3]);
    printf("%d\n", array[4]);
    printf("%d\n", array[5]);
    printf("%d\n", array[6]);
    printf("%d\n", array[7]);
    printf("%d\n", array[8]);
    printf("%d\n", array[9]);*/

    return 0;
}    