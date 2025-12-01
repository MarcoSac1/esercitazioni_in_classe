#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

/* ------------------- CODE ------------------- */

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

/* ------------------- SALVATAGGIO ------------------- */

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

/* Visualizza lo storico leggendo preferibilmente code.log (format con timestamp),
   se non presente prova a leggere code.txt (vecchio formato). */
void VisualizzaStorico(){
    FILE *fp;
    char buffer[512];

    /* 1) prova code.log */
    fp = fopen("code.log", "r");
    if (fp != NULL) {
        printf("\n--- STORICO (code.log) ---\n");
        while (fgets(buffer, sizeof(buffer), fp)) {
            /* Provo a parsare la riga log nel formato che usi:
            [dd/mm/yyyy hh:mm:ss] Cognome=%s Nome=%s Numero=%s Sportello=%d
               Se sscanf fallisce (es. formato diverso) stampo la riga grezza. */
            int d,m,y,hh,mm,ss, idx;
            char cogn[S], nome[S], numero[S];
            int parsed = sscanf(buffer,
                "[%d/%d/%d %d:%d:%d] Cognome=%99s Nome=%99s Numero=%99s Sportello=%d",
                &d, &m, &y, &hh, &mm, &ss,
                cogn, nome, numero, &idx);

            if (parsed == 10) {
                printf("\n[%02d/%02d/%04d %02d:%02d:%02d]\n",d,m,y,hh,mm,ss);
                printf("Cognome: %s\n", cogn);
                printf("Nome: %s\n", nome);
                printf("Numero linea: %s\n", numero);
                printf("Sportello: %d\n", idx);
                printf("------------------------\n");
            } else {
                /* riga con formato diverso: la stampo così com'è */
                printf("%s", buffer);
            }
        }
        fclose(fp);
        return;
    }

    /* 2) fallback su code.txt (vecchio formato) */
    fp = fopen("code.txt", "r");
    if (fp == NULL){
        printf("\nNessun dato salvato (code.log e code.txt non trovati).\n");
        return;
    }

    printf("\n--- STORICO (code.txt) ---\n");
    tipobaseQueue x;
    int indice;
    while (fscanf(fp, "%99s %99s %99s %d",x.cognome, x.nome, x.numero_linea, &indice) == 4) {
        printf("\nCognome: %s\n", x.cognome);
        printf("Nome: %s\n", x.nome);
        printf("Numero linea: %s\n", x.numero_linea);
        printf("Sportello: %d\n", indice);
        printf("------------------------\n");
    }
    fclose(fp);
}

void SalvaLog(tipobaseQueue x, int indiceCoda){
    FILE *fp = fopen("code.log", "a");
    if (fp == NULL){
        printf("Errore nell'apertura del file log!\n");
        return;
    }

    /* Ottieni data e ora */
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    /* Scrive sul file di log */
    fprintf(fp,
        "[%02d/%02d/%04d %02d:%02d:%02d] "
        "Cognome=%s Nome=%s Numero=%s Sportello=%d\n",
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec,
        x.cognome, x.nome, x.numero_linea, indiceCoda
    );

    fclose(fp);

    /* --- STAMPA SU TERMINALE --- */
    printf("\n--- LOG OPERAZIONE ---\n");
    printf("[%02d/%02d/%04d %02d:%02d:%02d]\n",
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec);

    printf("Cognome: %s\n", x.cognome);
    printf("Nome: %s\n", x.nome);
    printf("Numero linea: %s\n", x.numero_linea);
    printf("Sportello: %d\n", indiceCoda);
    printf("------------------------\n");
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

        if (scanf("%d", &s) != 1) { FFLUSH; continue; }
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
                    if (scanf("%d", &indice) != 1) { FFLUSH; indice = -1; }
                    FFLUSH;
                } while (indice < 0 || indice >= N);

                if (!FullQueue(archivio[indice])){
                    printf("\nInserisci Cliente");
                    LeggiElementoQueue(&elem);
                    EnQueue(&archivio[indice], elem);

                    /* salviamo sia il log con timestamp sia il vecchio file storico
                    (se vuoi mantenerli entrambi). Se preferisci solo code.log,
                       commenta SalvaSuFile(). */
                    SalvaLog(elem, indice);
                    SalvaSuFile(elem, indice);  /* facoltativo: mantiene code.txt */
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
                    if (scanf("%d", &indice) != 1) { FFLUSH; indice = -1; }
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
                    if (scanf("%d", &indice) != 1) { FFLUSH; indice = -1; }
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

            default:
                if (s != 5) printf("Scelta non valida\n");
                break;
        }

    } while (s != 5);

    return 0;
}
