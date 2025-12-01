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
    struct nodoQueue *tmp;
    tmp = (struct nodoQueue *)malloc(sizeof(struct nodoQueue));
    if (!tmp) return 1;
    else {
        free(tmp);
        return 0;
    }
}

void EnQueue(queue *q, tipobaseQueue x){
    struct nodoQueue * tmp;
    if (!FullQueue(*q)) {
        tmp = (struct nodoQueue *)malloc(sizeof(struct nodoQueue));
        tmp->info = x;
        tmp->next = CODAVUOTA;
        if (EmptyQueue(*q)) q->front = q->rear = tmp;
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
    if (!EmptyQueue(q)) {
        return(q.front->info);
    }
    tipobaseQueue empty = {0};
    return empty;
}

void LeggiStringa(char s[], unsigned long dim){
    unsigned long i;
    int c;
    for (i = 0; i < dim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
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

/* Funzione per visualizzare tutta una coda */
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

/* Funzione per visualizzare tutte le code */
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

queue archivio[N];

int main(){
    int i, s, indice;
    tipobaseQueue elem;
    
    for (i=0; i<N; i++)
        MakeNullQueue(&archivio[i]);
    
    do {
        printf("\n\nMenu di Operazioni:");
        printf("\n1 - Inserimento in coda");
        printf("\n2 - Servizio (visualizza ed estrai primo)");
        printf("\n3 - Visualizza persone in una coda");
        printf("\n4 - Visualizza tutte le code");
        printf("\n5 - Fine");
        printf("\nInserisci la scelta: ");
        scanf("%d", &s);
        FFLUSH;

        switch (s){
            case 1:
                do {
                    printf("\nIn quale sportello vuoi metterti in coda?\n");
                    printf("0 - Bollette e fatture\n1 - Guasti sulla linea\n2 - Sezione amministrativa\n3 - Telefonia mobile\nScelta: ");
                    scanf("%d", &indice);
                    FFLUSH;
                } while (indice < 0 || indice >= N);

                if (!FullQueue(archivio[indice])){
                    printf("\nInserisci Cliente");
                    LeggiElementoQueue(&elem);
                    EnQueue(&archivio[indice], elem);
                } else printf("\nCoda Piena\n");
                break;

            case 2:
                do {
                    printf("\nQuale sportello vuoi servire?\n");
                    printf("0 - Bollette e fatture\n1 - Guasti sulla linea\n2 - Sezione amministrativa\n3 - Telefonia mobile\nScelta: ");
                    scanf("%d", &indice);
                    FFLUSH;
                } while (indice < 0 || indice >= N);

                if (EmptyQueue(archivio[indice]))
                    printf("\nCoda Vuota\n");
                else {
                    elem = Front(archivio[indice]);
                    DeQueue(&archivio[indice]);
                    printf("\nPrimo Cliente:\n");
                    VisualizzaElementoQueue(elem);
                }
                break;

            case 3:
                do {
                    printf("\nQuale coda vuoi visualizzare?\n");
                    printf("0 - Bollette e fatture\n1 - Guasti sulla linea\n2 - Sezione amministrativa\n3 - Telefonia mobile\nScelta: ");
                    scanf("%d", &indice);
                    FFLUSH;
                } while (indice < 0 || indice >= N);

                VisualizzaCoda(archivio[indice]);
                break;

            case 4:
                VisualizzaTutteLeCode(archivio);
                break;
        }
    } while (s != 5);

    return 0;
}
