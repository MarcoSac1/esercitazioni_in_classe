#include <stdio.h>

int main() {

    char gender;
    int age = 0;

    printf("inserisci la tua eta'\n");
    scanf(" %d", &age);

    printf("inserisci il tuo genere \n");
    scanf(" %c", &gender);

    if (age >= 18 || gender == 'f'){
        printf(" puoi entrare %c --- %d", gender, age);
    }else{
        printf("sei minorenne non puoi entrare %c -- %d ", gender, age);
    }
    
    return 0;
}