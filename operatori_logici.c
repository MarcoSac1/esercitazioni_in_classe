#include <stdio.h>

int main() {
    int votoMatematica = 4;
    int votoCondotta = 6;
    //condizione con end "&&" che necessita di due condizioni vere
    if(votoMatematica <= 6 && votoCondotta < 7){
        printf("Sei bocciato %d -- %d\n", votoMatematica ,votoCondotta);
    }else{
        printf("Sei stato promosso !%d -- %d\n", votoMatematica ,votoCondotta);
    }
    return 0;
}