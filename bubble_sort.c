#include <stdbool.h>
#include <stdio.h>

#define ARRAY_MAX (10)

typedef int TInfo;  /* definizione tipo elemento array di interi */

bool greater(TInfo a, TInfo b)  /* ritorna true se a segue (è più grande di) b */
{
return a > b;
}

/* Scambia i valori di due informazioni
 * (lavorando con i puntatori all'indirizzo in memoria in cui tali valori risiedono e con una variabile di appoggio temp)
 */
void swap(TInfo *a, TInfo *b)
{
    TInfo temp=*a;
    *a=*b;
    *b=temp;
}

/* Ordinamento a bolle:
* Esamino gli elementi di un array a coppie adiacenti (0-1, 1-2, 2-3, etc.) 
* e scambio tra loro elementi della coppia se il 1^ è + grande del 2^.
* L’algoritmo ricomincia da capo e si ferma 
* quando nell’intera iterazione non vi siano + stati scambi. 
 */
void bubble_sort(TInfo a[], int n)
{
    int i, k;
    bool modified;

    modified=true; // l'inizializzazione a true serve a far eseguire la prima iterazione 
	                      // (anche se l'array di fatto non è stato ancora modificato)
/* il ciclo esterno gestisce le scansioni da effettuare con k = numero di scansioni completate
  * termina :
  *   - al raggiungimento del numero massimo di scansioni k==n-1
  *   -  O
  *   - se l'ultima scansione non ha modificato l'array (modified=false) 
  *       ovvero non ci sono state sostituzioni swap 
*/
    for(k=0; k<n-1 && modified; k++)
    {
        modified=false; // inizializzo modified a false ad inizio ciclo 
		                    // (non è ancora stata eseguita alcuna scansione)
/* il ciclo interno esamina tutte le coppie di elementi adiacenti a partire dal primo elemento a[0]
 * è dimostrato che dopo k scansioni, 
 * i k elementi più grandi - da a[n-k] all'ultimo a[n-1] - sono ordinati
 * quindi il ciclo si ferma quando i raggiunge il valore n-k-1
*/
        for(i=0; i<n-k-1; i++)
            if (greater(a[i], a[i+1]))
	     {
		// se dal confronto della coppia di valori il primo elemento è più grande del secondo,
		// li scambio tra loro con la funzione swap
                swap(&a[i], &a[i+1]);
                modified=true; // nell'iterazione corrente è stata effettuata almeno una modifica
            }
	if (k==n-1 || !modified)
		printf("\n\n array ordinato con BUBBLE SORT : ");
	else
		printf("\n\n array parziale dopo iterazione %d : ", k+1);
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n");
    }
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
	
	bubble_sort(vet, ARRAY_MAX);
}
