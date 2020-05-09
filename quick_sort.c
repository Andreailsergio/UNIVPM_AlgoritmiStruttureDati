#include <stdbool.h>
#include <stdio.h>

#define ARRAY_MAX (10)

typedef int TInfo;  /* definizione tipo elemento array di interi */

bool less(TInfo a, TInfo b)  /* ritorna true se a precede (è più piccolo di) b */
{
return a < b;
}

/* Scambia i valori di due informazioni
 * (lavorando con i puntatori all'indirizzo in memoria in cui tali valori risiedono 
 * e con una variabile di appoggio temp)
 */
void swap(TInfo *a, TInfo *b)
{
    TInfo temp=*a;
    *a=*b;
    *b=temp;
}

/* Suddivide l'array a in tre parti: 
 * -> 3^parte < 2^parte < 1^parte
 * - nella prima ci sono tutti elementi minori del pivot;
 * - nella seconda c'e' solo il pivot; 
 * - nella terza ci sono tutti elementi maggiori o uguali del pivot. 
 * Come pivot viene scelto il primo elemento dell'array iniziale.
 * VALORE DI RITORNO
 *    L'indice della parte centrale (che contiene il solo pivot)
 * PRE
 *    L'array contiene almeno un elemento */
int partition(TInfo a[], int n)
{
// k è l'indice del primo elemento successivo al sottoarray con valori < del pivot 
// -- inizialmente impostato ad 1 perchè l'elemento 0 è il pivot
 int i, k=1;
printf("elemento pivot : %d \n", a[0]);
 for(i=1; i<n; i++)
	{
	if (less(a[i], a[0]))  // se trovo un valore a[i] minore rispetto al pivot [a0] 
      // scambio e lo sposto in a[k] e contemporaneamente incremento k di 1
	// (gli elementi successivi al sottoarray inferiore - non ancora esaminati - partiranno 1 cella + in su)
	{
	printf("scambio %d \n",a[i]);
        swap(&a[i], &a[k++]);
	}}
   swap(&a[0], &a[k-1]); // al termine del ciclo scambio e sposto il pivot nella cella a[k-1] 
					  // - l'ultimo degli elementi inferiori al pivot
					  // NB se non ci sono elementi < pivot -> k varrà ancora 1 
					  // -> il pivot a[0] sarà scambiato con se stesso a[1-1]=a[0]
//    printf("elemento pivot : %d \n", a[k-1]);
    return k-1;				// la funzione partition restituisce il nuovo indice del pivot
}

/* Ordina un array con il Quick Sort:
* Per evitare di utilizzare array temporanei, partiziono l’array e mediante swap
* scambio e riordino gli elementi in base ad un elemento pivot 
* (per semplicità il primo elemento del vettore originario) 
* che dovrà risultare > = di tutti gli elementi precedenti e < = dei successivi. 
* Ottengo così 3 sottoinsiemi all’interno dello stesso array: il sottoinsieme con l’elemento pivot, 
* quello che contiene gli elementi inferiori e quello che contiene gli elementi superiori.
* Ordinando anche questi 2 segmenti utilizzando ricorsivamente la stessa funzione quick_sort, 
* alla fine otterrò un unico array ordinato.
 */
void quick_sort(TInfo a[], int n)
{
    int k, cont; // variabili intere
				// k x memorizzare indice del pivot 
				// cont contatore utile nella stampa dell'array riordinato
    if (n<2)	// Caso base: array di 1 elemento -> già ordinato - la ricorsione si ferma
	{
	printf("caso base\n");
        return;
	}
    // chiamo la funzione partition e ottengo l'indice del pivot che memorizzo in k
    printf("chiamata alla funzione PARTITION\n");
    k=partition(a, n);	
    //printf("k=%d\n",k);	
    // chiamata ricorsiva: ordino il sottoarray di elementi inferiori al pivot (a sx)
     // - i primi k elementi a partire dal primo a[0]
	printf("Primo quick_s\n");
	for (cont=0; cont<k+1; cont++)
	{
		if (cont==k) printf(" -- %d ", a[cont]);
		else printf("%d ", a[cont]);
	}
	printf("\n");
    quick_sort(a, k);
    // chiamata ricorsiva: ordino il sottoarray di elementi superiori/uguali al pivot (a dx)
     // - i successivi n-k-1 elementi a partire dal k+1esimo
	printf("Secondo quick_s\n");
	for (cont=n-k; cont<n; cont++)
	{
		printf("%d ", a[cont]);
	}
	printf("\n");
    quick_sort(a+k+1, n-k-1);
    // per ciascuna chiamata ricorsiva (ovvero ciascun sottoarray finchè n>=2) 
	// ripeto il partizionamento 
    // e trovo il nuovo indice del nuovo pivot che separa elementi inferiori e superiori/uguali

	printf("\n\n array (alla fine) ordinato con QUICK SORT : \n\n");
	for (cont=0; cont<n; cont++)
	{
		printf("%d ", a[cont]);
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
	vet[7]=52;
	vet[8]=9;
	vet[9]=30;
	
	printf(" array originario : ");
	for (cont=0; cont<ARRAY_MAX; cont++)
	{
		printf("%d ", vet[cont]);
	}
	printf("\n\n");
	quick_sort(vet, ARRAY_MAX);



}
