#include <stdio.h>
#include <string.h>

void leggiStringa(char str[], int dim) {
    fgets(str, dim, stdin);
    if (str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
}

#define NUM_USERS 2

struct persona {
    char nome[30];
    char cognome[30];
    int eta;
};

int main(void) {
    struct persona users[NUM_USERS];
    int i;

    for (i = 0; i < NUM_USERS; i++) {
        printf("inserisci il nome: ");
        leggiStringa(users[i].nome, sizeof users[i].nome);

        printf("inserisci il cognome: ");
        leggiStringa(users[i].cognome, sizeof users[i].cognome);

        printf("inserisci l'eta': ");
        scanf("%d", &users[i].eta);
        getchar();

        printf("Registrato: %s %s, eta %d\n", users[i].nome, users[i].cognome, users[i].eta);
    }

    for ( i = 0; i < NUM_USERS; i++){
    printf("gli utenti registrati al tuo sito sono :  %s %s, eta- %d\n", users[i].nome, users[i].cognome, users[i].eta);
        
    }
    
    return 0;
}