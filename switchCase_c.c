#include <stdio.h>

int main() {
    char giorno;

    printf("inserisci la lettera corrispondente al giorno che vorresti selezionare\n");
    
    giorno = getchar(); // getchar funziona come scanf() in questo caso

    switch (giorno){
    case 'l':
        printf("Lunedi'");
        break;

    case'm':
        printf("Martedi'");
        break;

    case'M':
        printf("Mercoledi'");
        break;

    case'g':
        printf("giovedi'");
        break;

    case'v':
        printf("Venerdi'");
        break;

    case's':
        printf("Sabato");
        break;

    case'd':
        printf("Domenica");
        break;

    default :
    printf("lettera non valida");
        break;
    }
    return 0;
}