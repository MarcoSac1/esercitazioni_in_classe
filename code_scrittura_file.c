#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S 100
#define N 4

typedef struct{
    char cognome[S], nome[S];
    char numero_linea[S];
} tipobaseQueue;

typedef short boolean;

struct nodoQueue{
    tipobaseQueue info;
    struct nodoQueue *next;
};

typedef struct{
    struct nodoQueue *front, *rear;
} queue;

#define CODAVUOTA NULL
#define FFLUSH while(getchar()!='\n')

void MakeNullQueue(queue *q){
    q->front = q->rear = CODAVUOTA;
}

boolean EmptyQueue(queue q){
    return(q.front == CODAVUOTA);
}

boolean FullQueue(queue q){
    struct nodoQueue *tmp = (struct nodoQueue *)malloc(sizeof(struct nodoQueue));
    if (!tmp) return 1;
    free(tmp);
    return 0;
}

void EnQueue(queue *q, tipobaseQueue x){
    struct nodoQueue *tmp;
    if (!FullQueue(*q)){
        tmp = (struct nodoQueue *)malloc(sizeof(struct nodoQueue));
        tmp->info = x;
        tmp->next = CODAVUOTA;

        if (EmptyQueue(*q))
            q->front = q->rear = tmp;
        else {
            q->rear->next = tmp;
            q->rear = tmp;
        }
    }
}

void DeQueue(queue *q){
    struct nodoQueue *tmp;
    if (!EmptyQueue(*q)) {
        tmp = q->front->next;
        free(q->front);
        q->front = tmp;
        if (q->front == CODAVUOTA) q->rear = CODAVUOTA;
    }
}

tipobaseQueue Front(queue q){
    if (!EmptyQueue(q))
        return q.front->info;

    tipobaseQueue empty = {0};
    return empty;
}

void LeggiStringa(char s[], unsigned long dim){
    unsigned long i;
    int c;
    for (i = 0; i < dim - 1 && (c = getchar()) != '\n' && c != EOF; i++)
        s[i] = (char)c;
    s[i] = '\0';
    if (i == dim-1) FFLUSH;
}

void LeggiElementoQueue(tipobaseQueue *x){
    printf("\nInserisci il Cognome: ");
    LeggiStringa(x->cognome, S);
    printf("Inserisci il Nome: ");
    LeggiStringa(x->nome, S);
    printf("Inserisci il tuo numero di linea fissa: ");
    LeggiStringa(x->numero_linea, S);
}

void VisualizzaElementoQueue(tipobaseQueue x){
    printf("\nCognome = %s", x.cognome);
    printf("\nNome = %s", x.nome);
    printf("\nNumero utenza telefonica = %s\n", x.numero_linea);
}

void VisualizzaCoda(queue q){
    struct nodoQueue *p = q.front;
    if (!p){
        printf("\nLa coda è vuota.\n");
        return;
    }

    printf("\n--- Persone in coda ---\n");
    while (p != NULL){
        VisualizzaElementoQueue(p->info);
        printf("------------------------\n");
        p = p->next;
    }
}

void VisualizzaTutteLeCode(queue archivio[]){
    char *nomiSportelli[N] = {
        "Bollette e fatture",
        "Guasti sulla linea",
        "Sezione amministrativa",
        "Telefonia mobile"
    };

    for (int i = 0; i < N; i++){
        printf("\n========== %s ==========\n", nomiSportelli[i]);
        VisualizzaCoda(archivio[i]);
    }
}

void SalvaSuFile(tipobaseQueue x, int indiceCoda){
    FILE *fp = fopen("code.txt", "a");
    if (fp == NULL){
        printf("Errore nell'apertura del file!\n");
        return;
    }

    fprintf(fp, "%s %s %s %d\n",
            x.cognome,
            x.nome,
            x.numero_linea,
            indiceCoda);

    fclose(fp);
}

void VisualizzaStorico(){
    FILE *fp = fopen("code.txt", "r");
    if (fp == NULL){
        printf("\nNessun dato salvato.\n");
        return;
    }

    tipobaseQueue x;
    int indice;

    printf("\n--- STORICO COMPLETO ---\n");

    while (fscanf(fp, "%s %s %s %d",
        x.cognome,
        x.nome,
        x.numero_linea,
        &indice) == 4){

        printf("\nCognome: %s", x.cognome);
        printf("\nNome: %s", x.nome);
        printf("\nNumero linea: %s", x.numero_linea);
        printf("\nSportello: %d", indice);
        printf("\n------------------------");
    }

    fclose(fp);
}

queue archivio[N];

int main(){
    int i, s, indice;
    tipobaseQueue elem;

    for (i = 0; i < N; i++)
        MakeNullQueue(&archivio[i]);

    do {
        printf("\n\nMenu di Operazioni:");
        printf("\n1 - Inserimento in coda");
        printf("\n2 - Servizio (visualizza ed estrai primo)");
        printf("\n3 - Visualizza persone in una coda");
        printf("\n4 - Visualizza tutte le code");
        printf("\n5 - Fine");
        printf("\n6 - Visualizza storico salvato su file");
        printf("\nScelta: ");

        scanf("%d", &s);
        FFLUSH;

        switch (s){

            case 1:
                do {
                    printf("\nIn quale sportello vuoi metterti in coda?");
                    printf("\n0 - Bollette e fatture");
                    printf("\n1 - Guasti sulla linea");
                    printf("\n2 - Sezione amministrativa");
                    printf("\n3 - Telefonia mobile");
                    printf("\nScelta: ");
                    scanf("%d", &indice);
                    FFLUSH;
                } while (indice < 0 || indice >= N);

                if (!FullQueue(archivio[indice])){
                    printf("\nInserisci Cliente");
                    LeggiElementoQueue(&elem);
                    EnQueue(&archivio[indice], elem);
                    SalvaSuFile(elem, indice);   // <--- SALVA NEL FILE
                }
                else printf("\nCoda piena\n");
                break;

            case 2:
                do {
                    printf("\nQuale sportello vuoi servire?");
                    printf("\n0 - Bollette e fatture");
                    printf("\n1 - Guasti sulla linea");
                    printf("\n2 - Sezione amministrativa");
                    printf("\n3 - Telefonia mobile");
                    printf("\nScelta: ");
                    scanf("%d", &indice);
                    FFLUSH;
                } while (indice < 0 || indice >= N);

                if (EmptyQueue(archivio[indice]))
                    printf("\nCoda vuota\n");
                else {
                    elem = Front(archivio[indice]);
                    DeQueue(&archivio[indice]);
                    printf("\nPrimo cliente:\n");
                    VisualizzaElementoQueue(elem);
                }
                break;

            case 3:
                do {
                    printf("\nQuale coda vuoi visualizzare?");
                    printf("\n0 - Bollette e fatture\n1 - Guasti sulla linea\n2 - Sezione amministrativa\n3 - Telefonia mobile");
                    printf("\nScelta: ");
                    scanf("%d", &indice);
                    FFLUSH;
                } while (indice < 0 || indice >= N);

                VisualizzaCoda(archivio[indice]);
                break;

            case 4:
                VisualizzaTutteLeCode(archivio);
                break;

            case 6:
                VisualizzaStorico();
                break;
        }

    } while (s != 5);

    return 0;
}
