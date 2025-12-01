#include <stdio.h>
#include <stdlib.h>



int main() {
    int i;
    int N;
    
    printf("inserisci la dimensione di N\n");
    scanf("%d",&N);

    int *array= malloc(N *sizeof(int));
    for ( i = 0; i < N; i++){
        printf("alla %d°iterazione il puntatore e'%d\n",i+1, &array[i]);
        
    }
    free(array);
    printf("%ddopo aver utilizato il free", &array[i]);
    

    return 0;
}