#include <stdio.h>
#include <string.h>
#define N 10
char s[N];
int i;
int main()
{
    printf("\n------ USO SCANF ERRATO -----");
    printf("\nInserisci una stringa "); 
    scanf("%s", s);
    while (getchar() != '\n')
        ;
    printf("\nLa stringa inserita e': %s ", s);
    printf("\ned ha lunghezza %lu ", strlen(s));
    printf("\n\n-----USO SCANF che gestisce gli spazi ma non la lunghezza -----");
    printf("\nInserisci una stringa ");
    scanf("%[^\n]s", s);
    while (getchar() != '\n')
        ;
    printf("\nLa stringa inserita e': %s ", s);
    printf("\ned ha lunghezza %lu ", strlen(s));

    printf("\n\n----USO FGETS che gestisce gli spazi e la lunghezza ------");
    printf("\nFGETS legge al massimo i successivi N-1 caratteri ");
    printf("\noppure si ferma se trova un carattere di newline ");
    printf("\nche e' inserito nel vettore prima del carattere fine stringa");
    printf("\n\nInserisci una stringa ");
    fgets(s, N, stdin);
    i = strlen(s);
    printf("\nLa stringa inserita e': %s ", s);
    printf("\ned ha lunghezza %d ", i);
    if (i < N - 1)
        s[i - 1] = '\0';
    else
        while (getchar() != '\n')
            ;
    printf("\nLa stringa inserita e': %s ", s);
    printf("\ned ha lunghezza %lu ", strlen(s));

    printf("\n\n-----USO getchar() CORRETTO-----");
    printf("\nInserisci una stringa ");
    for (i = 0; i < N - 1; i++)
        if ((s[i] = getchar()) == '\n')
            break;
    if (i == N - 1)
        while (getchar() != '\n')
            ;
    s[i] = '\0';
    printf("\nLa stringa inserita e': %s ", s);
    printf("\ned ha lunghezza %lu \n\n\n", strlen(s));
    getchar();
}