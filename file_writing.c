#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    char cognome[30];
    int eta;
} Utente;

int main() {
    FILE *fp;
    Utente u;
    int scelta;
    char continua;

    do {
        printf("\n--- MENU ANAGRAFICA ---\n");
        printf("---1) Aggiungi utente---\n");
        printf("---2) Visualizza utenti---\n");
        printf("---3) Esci ---\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {

            case 1: {
                // APRIAMO IL FILE IN APPEND
                fp = fopen("anagrafica.txt", "a");
                if (fp == NULL) {
                    printf("Errore apertura file!\n");
                    return 1;
                }

                do {
                    printf("\n--- INSERIMENTO UTENTE ---\n");

                    printf("--Inserisci nome: ");
                    scanf("%s", u.nome);

                    printf("--Inserisci cognome: ");
                    scanf("%s", u.cognome);

                    printf("--Inserisci eta: ");
                    scanf("%d", &u.eta);

                    // Salvataggio
                    fprintf(fp, "%s %s %d\n", u.nome, u.cognome, u.eta);

                    // Chiedo se continuare
                    printf("\nVuoi inserire un altro utente? (s/n): ");
                    scanf(" %c", &continua);

                } while (continua == 's' || continua == 'S');

                fclose(fp);
                break;
            }

            case 2: {
                fp = fopen("anagrafica.txt", "r");
                if (fp == NULL) {
                    printf("Nessun utente registrato!\n");
                    break;
                }

                printf("\n--- LISTA UTENTI ---\n");

                while (fscanf(fp, "%s %s %d", u.nome, u.cognome, &u.eta) == 3) {
                    printf("Nome: %s | Cognome: %s | Eta: %d\n",u.nome, u.cognome, u.eta);
                }

                fclose(fp);
                break;
            }

            case 3:
                printf("Uscita...\n");
                break;

            default:
                printf("Scelta non valida!\n");
        }

    } while (scelta != 3);

    return 0;
}
