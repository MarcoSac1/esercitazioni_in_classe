// sono necessari 2 cicli obligatoriamente

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int e; 
    int f;
    int temp;
    int array[] = {7 ,34 ,59 ,48 ,1 , 4 ,9 ,78};
    int length = sizeof(array)/sizeof(array[0]);

    for ( i = 0; i < length-1; i++){
        
        for (e = 0; e < length-1; e++)
        {
            if(array[e] > array[e+1]){
                temp = array[e];
                array[e] = array[e+1];
                array[e+1] = temp;
            }
        }
        
    }

    for ( f = 0; f < length; f++)
    {
        printf("ciclo - [%d] = %d\n",f+1 , array[f]);
    }

    return 0;
}