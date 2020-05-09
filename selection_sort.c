#include <stdbool.h>
#include <stdio.h>

#define ARRAY_MAX (10)

typedef int TInfo;  /* definizione tipo elemento array di interi */

bool less(TInfo a, TInfo b)  /* ritorna true se a precede b / false per a uguale o superiore a b */
{
return a < b;
}

/* Scambia i valori di due informazioni
 * (lavorando con i puntatori all'indirizzo in memoria in cui tali valori risiedono e 
 *  con una variabile di appoggio temp)
 */
void swap(TInfo *a, TInfo *b)
{
    TInfo temp=*a;
    *a=*b;
    *b=temp;
}

/* Ricerca la posizione del minimo in un array.
 * PRE: n>0
 * la funzione memorizza la posizione del minimo parziale che, a fine iterazione, 
 * è il minimo dell'intero array
 */
int search_min(TInfo a[], int n)
{
    int i, imin;
    imin=0;
    for(i=1; i<n; i++)
        if (less(a[i], a[imin]))
            imin=i;
    return imin;
}

/* Ordina l'array a con l'algoritmo di ordinamento per selezione, ovvero:
* Cerco il minimo tra gli elementi di un array e lo metto al primo posto.
* Poi cerco il minimo tra gli elementi rimanenti e lo metto al secondo posto ... e così via.
 */
void selection_sort(TInfo a[], int n)
{
	int i, imin;
	for(i=0; i<n-1; i++) // bastano n-1 iterazioni - l'ultimo elemento trovato è minimo di se stesso
	{
		/* alla funzione search_min non passo l'intero vettore, ma:
		 *  - il puntatore all'elemento iesimo -> il primo elemento della parte non ancora ordinata
		 *  - il numero n-i di elementi della parte non ancora ordinata
		 * dalla funzione search_min ricevo la posizione del minimo 
		 * all'interno della porzione di array trasmessa
		 * tale posizione va sommata ad i (numero di elementi della parte già ordinata)
		 * per ottenere l'indice del minimo rispetto all'intero array
		*/
        	imin=i+search_min(a+i, n-i);
        	if (imin!=i) 
			// effettuo uno scambio di posizione in memoria tra l'ultimo minimo trovato a[imin] 
			// ed il primo elemento successivo alla parte già ordinata a[i], 
			// a meno che già non coindano
			swap(&a[i], &a[imin]);
	}
	printf("\n\n array ordinato con SELECTION SORT : ");
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n");
}

int main()
{
	/* definizione vettore monodimensionale e suo riempimento con sequenza di numeri interi */
	int cont;
	TInfo vet[ARRAY_MAX];
	vet[0]=12;
	vet[1]=1;
	vet[2]=8;
	vet[3]=17;
	vet[4]=25;
	vet[5]=3;
	vet[6]=44;
	vet[7]=12;
	vet[8]=9;
	vet[9]=30;
	
	printf(" array originario : ");
	for (cont=0; cont<ARRAY_MAX; cont++)
	{
		printf("%d ", vet[cont]);
	}
	
	selection_sort(vet, ARRAY_MAX);
}
