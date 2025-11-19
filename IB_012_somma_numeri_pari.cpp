# include <stdio.h>
int main(){
	
	int nutente, somma, i;	
	
	printf("inserisci un numero! \n");
	scanf("%d",&nutente);
	somma=0;
	for (i=0; i <= nutente; i++){
		if(i % 2==0){
			somma+=i;
			printf("ciclo %d - somma= %d\n", i,somma);
		}else{
			printf("%d ed il tuo numero e  dispari\n",i ,somma);
		}
	}
	
	printf("la somma finale e = %d\n, somma");
}
