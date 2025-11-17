#include<stdio.h>
#include<string.h> 
#define N 10
// if con piu condizioni
int main(){

    int e,v,c;
	char sesso;
	int pagato=2;

	printf("---VUOI ENTRARE IN DISCOTECA---");
	printf("\nQuanti anni hai?-->");
	scanf("%d",&e);
	getchar();
	printf("\nSei uomo o donna? \n(digita D per donna U per uomo)--->");
	sesso=getchar();
	if(sesso!='D'){
		printf("\nvuoi pagare?\n (1 per si 0 per no)--->");
		scanf("%d",&pagato);
	}
	if(e>17&&(pagato==1||sesso=='D')){
		printf("\nPuoi entrare");
	}else{
		if(e<17)printf("\nSei troppo piccolo/a per entrare.");
        if(pagato!=2&&pagato!=1)printf("\nVisto che sei maschio devi pagare per entrare.");
	}
	
}