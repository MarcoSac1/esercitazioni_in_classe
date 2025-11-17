#include <stdio.h>

int main() {
    int votoMatematica;
    int votoCondotta;

    do
    {
        printf("inserisci il voto di Matematica\n");
        scanf("%d ", &votoMatematica);

        printf("inserisci il voto di Condotta\n");
        scanf("%d ", &votoCondotta);
    } while (votoCondotta > 10 || votoMatematica < 0);
    
    //condizione con end "&&" che necessita di due condizioni vere
    if(votoMatematica <= 6 && votoCondotta < 7){
        printf("Sei bocciato %d -- %d\n", votoMatematica ,votoCondotta);
    }else{
        printf("Sei stato promosso !%d -- %d\n", votoMatematica ,votoCondotta);
    }
    return 0;
}