/*crea un array con duplicati ordinalo e togli i duplicati*/
#include <stdio.h>
#include <stdbool.h>

#define DIN 6


void selection_sort(int arr[], int lunghezza){
    int v, l;
    int numero_minore;

    for ( v = 0; v < lunghezza-1; v++)
    {
        numero_minore=1;
        for ( l = v; l< lunghezza; v++)
        {
            if (arr[l] < arr[numero_minore]){
                numero_minore =l;
            }
        }
        
    }
    
}


int main() {
    int i, j;
    int array[DIN] = {1, 2, 2, 4, 5, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int newArray[DIN];
    int K = 0;

    for (i = 0; i < length; i++) {
        bool isPresent = false;
        
        if (!isPresent) {
            newArray[K] = array[i];
            K++;
            printf("primo array  %d\n", array[i]);
        }
    }
    
    printf("\nArray senza duplicati:\n");
    for (i = 0; i < K; i++) {
        printf("%d ", newArray[i]);
    }
    printf("\n");
    
    return 0;
}