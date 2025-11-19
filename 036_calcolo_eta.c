//crea una funzione che dato l'anno di nascita e l'anno attuale ti calcola l'eta'
#include <stdio.h>


int calcoloEta(int annoNascita, int annoAttuale){
    return annoAttuale - annoNascita;
}


int main() {

    int a, b;
    int etaCalcolata;
    printf("inserisci l'anno di nascita\n");
    scanf("%d", &a);
    printf("inserisci l'anno attuale\n");
    scanf("%d", &b);
    etaCalcolata = calcoloEta(a, b);
    
    if(etaCalcolata < 0){
        etaCalcolata =-etaCalcolata;
    } 
    printf("la tua eta' e' %d\n", etaCalcolata);

}