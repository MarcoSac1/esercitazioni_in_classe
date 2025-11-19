#include <stdio.h>
#include <string.h>



void leggiStringa (char str[], int dim) {
    fgets(str, dim, stdin);
    if (str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
    else
        while (getchar()!='\n');
}

#define NUM_WORKER 2
/*#define FFLUSH  while(getchar()!=' \n'); //serve a ripulire il buffer*/


struct workers{
    char nome[30];
    char cognome[30];
    int salario;
};

int main(void) {
    
    struct workers work[NUM_WORKER];
    int i ;
    int media = 0;
    int salario_tot = 0;
    int min = work[0].salario;
    int max = work[0].salario;

    for ( i = 0; i < NUM_WORKER; i++)
    {
        printf("inserisci il nome: ");
        leggiStringa(work[i].nome, sizeof work[i].nome);

        printf("inserisci il cognome: ");
        leggiStringa(work[i].cognome, sizeof work[i].cognome);

        printf("inserisci il tuo salario: ");
        scanf("%d", &work[i].salario);
        //FFLUSH //si usa perche piu efficace ma non funziona bene per me

        getchar(); 

        printf("Dati inseriti corrrettamente : %s %s, salario %d\n", work[i].nome, work[i].cognome, work[i].salario);
    }
    for ( i = 0; i < NUM_WORKER; i++){
        printf("%d\n", max);
        if(work[i].salario > max){
            max = work[i].salario;
        }if (work[i].salario < min){  
            min = work[i].salario;
        }
        salario_tot += work[i].salario;
    }
    printf("il salario minimo e' %d \n", min);
    printf("il salario massimo e' %d \n", max);

    media=salario_tot/NUM_WORKER;
    printf("la media degli stipendi e' %d\n", media);

}