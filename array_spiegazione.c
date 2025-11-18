/*In C, un array è una struttura dati 
che permette di memorizzare più valori dello stesso 
tipo all’interno di un’unica variabile. Gli elementi 
dell’array sono salvati in posizioni di memoria contigue e 
sono accessibili tramite un indice nel nostro caso numeri[i], che parte sempre da 0 fino a N−1, 
dove N è la lunghezza dell’array.*/

#include <stdio.h>
# define DIM 5

int main() {

    int i;
    int numeri[5] = {10, 20, 30, 40, 50};

    /*In C non esiste un funzione integrata che restituisce automaticamente
    la lunghezza di un array.Per questo, quando l’array è definito nello 
    stesso scope, si utilizza la  seguente formula:*/

    int length = sizeof(numeri) / sizeof(numeri[0]);

    //sizeof restituisce la quantita' di memoria occupata 
    //sizeof(numeri) e' il numero totale di byte dell'array -> 20 byte (5 valori x 4byte)
    //sizeof(numeri[0]) e' il numero di byte del singolo elemento -> 4 byte
    // e' buona norma utilizare sempre questa formula per ciclare gli array questa 
    // fa si che i nostri cicli si adattino automaticamente alla dimensione dell'array

    /*Per scorrere tutti gli elementi di un array si utilizza comunemente un ciclo for,
    in cui si parte dall’indice 0 e si prosegue fino all’ultimo elemento:*/

    for (int i = 0; i < length; i++) {
    printf("al ciclo %d il numero presente al posto %d del nostro array e':%d \n", i+1, i, numeri[i]);
}


    return 0;
}