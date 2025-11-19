#include<ctype.h>
#include<stdio.h>
#include<string.h>

#define DIM 20

void leggiStringa (char str[], int dim) {
    fgets(str, dim, stdin);
    if (str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
    else
        while (getchar()!='\n');
}

int main(){

    char password[DIM];
    int lunghezza;

    while (1) {
        printf("insersci una password di almeno 6 caratteri con una maiuscola : ");
        leggiStringa(password, DIM);
        lunghezza = strlen(password);

        if (lunghezza < 4 || toupper()) {
            printf("password non valida troppo corta o poco sicura\n");
        } else {
            printf("il tuo password e' disponibile\n");
            printf("password = %s\n", password);
            printf("lunghezza password = %lu\n", strlen(password));
            break;
        }
    }

    return 0;
}