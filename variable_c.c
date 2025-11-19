#include <stdio.h>

int main() {
    char carattere = 'r';
    printf(" il tuo carattere e' %c <--", carattere );
    printf("inserisci il nuovo carattere\n" );
    scanf("%c", &carattere);
    printf("%c e' il carattere che hai inserito", carattere);
    return 0;
}