//3 array v1, v2, v3, [10], nei primi 2 dati messi da tastiera e l'altro somma
#include <stdio.h>

int main(){
	int i, v1[10], v2[10], v3[10];
	
	for(i=0; i<10; i++)
	{
		printf("Inserisci il %d^ numero per il primo vettore: ", i+1);
		scanf("%d", &v1[i]);
	}
	
	for(i=0; i<10; i++)
	{
		printf("Inserisci %d^ numero per il secondo vettore: ", i+1);
		scanf("%d", &v2[i]);
	}
	
	for(i=0; i<10; i++)
	{
		v3[i]=v1[i]+v2[i];
		printf("La somma dei %d^ numeri dei 2 array e': %d\n", i+1, v3[i]);
		
	}
}