#include <stdio.h>

int array[10];

int main() {

    int length =sizeof(array)/sizeof(array[0]);


    for (int i = 0; i < length; i++)
    {
        printf(" %d - %d\n", i, array[i]);
    }
    
    return 0;
}