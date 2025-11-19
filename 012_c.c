#include <stdio.h>

int main() {
    
    int somma =0;
    for(int i=0; i<=100; i++){
        somma = i+somma;
        printf("ciclo %d -somma = %d\n", i, somma);
    }
    return 0;
}