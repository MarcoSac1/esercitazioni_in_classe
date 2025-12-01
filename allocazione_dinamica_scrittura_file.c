#include <stdio.h>
#include <stdlib.h>


int main() {
    int i;
    int N;
    
    printf("inserisci la dimensione di N\n");
    scanf("%d",&N);
    int *array = malloc(N * sizeof(int));

    
    FILE *fp=fopen("puntatori.txt", "w");
    if(fp==NULL){
        printf("errore nell'apertura del file \n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        array[i] = i + 1;   
    }

    for ( i = 0; i < N; i++){
        printf("%d\n", array[i]);
    }
    for ( i = 0; i < N; i++){
        fprintf(fp, "%d\n", array[i]);
    }
    fclose(fp);


    return 0;
}