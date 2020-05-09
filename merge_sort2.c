#include <stdbool.h>
#include <stdio.h>

#define ARRAY_MAX (7)

typedef int TInfo;  /* definizione tipo elemento array di interi */

bool less(TInfo a, TInfo b)  /* ritorna true se a precede (è più piccolo di) b */
{
return a < b;
}

/* MERGE: Fonde due array ordinati in un nuovo array che conserva l'ordinamento.
* In un vettore di appoggio riporto, a partire dal primo elemento, 
* l’elemento più piccolo tra i primi elementi di ciascuno dei due sottoarray ordinati;
* poi nel secondo posto riporto l’elemento più piccolo tra i primi elementi rimanenti 
* in ciascuno dei due sottoarray, e così via fino alla fine.
 */
void merge(TInfo a1[], int n1, TInfo a2[], int n2, TInfo dest[])
{
    int pos1=0, pos2=0, k=0; // pos1 è l'indice del primo elemento inutilizzato del segmento a1[]
	                                     // pos2 del secondo 
	                                     // k è l'indice dell'array temporaneo dest[]

    while (pos1<n1 && pos2<n2) // il primo while viene eseguito finchè in entrambi i segmenti 
		                                    // ci sono elementi da utilizzare
    {
	// il minor elemento tra il primo inutilizzato di a2[] ed il primo inutilizzato di a1[] 
	// viene copiato nell'array dest
	// poi incremento k e pos1 o pos2 (a seconda di quale elemento ho utilizzato) e proseguo
        if (less(a2[pos2], a1[pos1]))	
            dest[k++] = a2[pos2++];
        else
            dest[k++] = a1[pos1++];
    }

    while (pos1<n1)		// il secondo ciclo while si esegue se restano elementi di a1[] inutilizzati
        dest[k++] = a1[pos1++]; // (essendo elementi già ordinati li copio nello stesso ordine in dest[])

    while (pos2<n2)		// il terzo ciclo while si esegue se restano elementi di a2[] inutilizzati
        dest[k++] = a2[pos2++]; // (analogamente li copio nello stesso ordine in dest[])
}

/* Ordinamento con l'algoritmo Merge Sort:
* Divido un array a metà in 2 sottoarray 
* (che ordino chiamando ricorsivamente per ciascuno la stessa funzione merge_sort).
 * Nota: temp e' un array di appoggio delle stesse dimensioni di a
 */
void merge_sort(TInfo a[], int n, TInfo temp[])
{
    int i, m=n/2;
    if (n<2) // CASO BASE: se il numero di elementi è 1 il vettore è già ordinato 
		  // (la ricorsività non è infinita - si interrompe quando ottengo il caso base)
    {
	//printf("\n trovato caso base: elemento %d\n", a[0]);
	printf("caso base %d\n",a[m]);
	return;
    }
	// altrimenti
	// DIVIDE: divido array in 2 parti: la prima di m=n/2 elementi (da a[0] ad a[m-1]); 
	//   la seconda di n-m elementi (da a[m] ad a[n])
	// IMPERA: sono in grado di ordinare i due segmenti di array applicando ricorsivamente 
	//   l'algoritmo merge_sort stesso
	//   la prima chiamata ricorsiva di merge_sort lavora per ordinare la prima parte di array
	//   la seconda chiamata ricorsiva lavora con la seconda parte di array
	// COMBINA: chiamiamo la funzione merge per fondere i due segmenti ordinati 
	//   in un nuovo array - che viene restituito
	// NB: si passa ogni volta l'array di appoggio temp che comunque 
	// al termine di ogni esecuzione non mantiene informazioni conservate §
	 printf("1^ mergesort ");
    merge_sort(a, m, temp);
	 printf("2^ mergesort ");
    merge_sort(a+m, n-m, temp); // a+m corrisponde all'indirizzo dell'elemento a[m] 
	                                            // cioè il primo elemento della seconda parte 
	                                            // (l'array viene passato per riferimento)
	 printf("faccio merge %d - %d\n", a[0], a[0+m]);
    merge(a, m, a+m, n-m, temp); // chiamo MERGE passando il primo vettore e sua dimensione,
	                                             // il secondo vettore e la sua dimensione, il vettore temporaneo

    for(i=0; i<n; i++)
    {
        a[i]=temp[i]; // § proprio perchè temp[] non conserva i dati, 
		             // ripasso gli elementi ordinati all'area di memoria iniziale a[]
		             // e stampo a video il nuovo vettore finale riordinato
	 printf("%d ", a[i]);
    }
    printf("\n\n");
}

int main()
{
	/* definizione vettore monodimensionale e suo riempimento con sequenza di numeri interi 
	*   e definizione vettore di appoggio */
	int cont;
	TInfo tempvet[ARRAY_MAX];
	TInfo vet[ARRAY_MAX];
	vet[0]=12;
	vet[1]=1;
	vet[2]=8;
	vet[3]=17;
	vet[4]=25;
	vet[5]=3;
	vet[6]=44;
//	vet[7]=12;
//	vet[8]=9;
//	vet[9]=30;	
	
	printf(" array originario : ");
	for (cont=0; cont<ARRAY_MAX; cont++)
	{
		printf("%d ", vet[cont]);
	}
	printf("\n\n array ordinato con MERGE SORT : \n\n");
	
	merge_sort(vet, ARRAY_MAX, tempvet);

	printf("\n\n");
}
