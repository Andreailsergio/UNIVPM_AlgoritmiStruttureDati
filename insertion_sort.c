#include <stdbool.h>
#include <stdio.h>

#define ARRAY_MAX (4)

typedef int TInfo;  /* definizione tipo elemento array di interi */

bool greater(TInfo a, TInfo b)  /* ritorna true se a segue (è più grande di) b */
{
return a > b;
}

/* Inserisce un elemento in un array gia' ordinato
 * in modo da mantenere l'ordinamento.
 * PRE: - l'array a e' ordinato secondo la funzione less
 *      - l'array e' dimensionato in modo da poter contenere
 *        almeno n+1 elementi
 */
void insert_in_order(TInfo a[], int n, TInfo x)
{
    int pos, i;
/* Cerca la posizione di inserimento usando versione iterativa modificata della ricerca lineare :
* partendo da ultimo elemento del segmento già ordinato e tornando indietro ad ogni iterazione
* il ciclo all'indietro termina :
* -- se non ci sono altri elementi da esaminare  
* (pos=0 ovvero la posizione è quella del primo elemento dell'array - l'ultimo del ciclo)
	* -- O
* -- se l'elemento correntemente esaminato a[pos-1] è <= dell'elemento passato x 
* (finchè invece è più grande il ciclo può continuare)
* la variabile pos rappresenta l'indice dell'elemento successivo a quello che stiamo controllando, 
* ma, poichè l'iterazione va all'indietro,
* la posizione di inserimento pos risultante sarà quella immediatamente precedente 
* all'ultimo elemento che sia risultato > x   */
    for(pos=n; pos>0 && greater(a[pos-1], x); pos--)
    	printf("\n      --> devo mettere il numero %d al posto del numero %d \n", x, a[pos-1]);
    	/* prima di inserire l'elemento passato nella posizione individuata pos 
	* sposto in avanti tutti gli elementi da pos in poi 
	* a partire dall'ultimo elemento di questo segmento e tornando indietro fino a pos 
	* (ecco perchè il vettore deve avere dimensione n+1) */
    	for(i=n-1; i>=pos; i--)
       		a[i+1]=a[i];
       /* Inserisce l'elemento passato alla corretta posizione pos, che si è liberata 
	* (o è già occupata dall'elemento stesso)
	*  [rappresentiamo pos col numero pos+1 affinchè la prima posizione sia indicata da 1 
	* e non da 0] */
	printf("\n      --> il numero %d va (o resta) in posizione %d \n", x, pos+1);
	a[pos]=x;
	
	if (n<ARRAY_MAX-1)
		printf("\n array parziale dopo iterazione %d : ", n);
	else
		printf("\n array definitivo ordinato con INSERTION SORT : ");
	for (i=0; i<ARRAY_MAX; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

/* Ordinamento per inserimenti successivi, ovvero:
* Prendo 1 alla volta gli elementi dell'array e li inserisco in ordine in un nuovo array 
* (scorrendolo all’indietro nella funzione insert_in_order).
* Spostando in avanti tutti gli elementi seguenti rispetto a quello inserito 
* posso evitare l’uso di un nuovo array (effettuando un inserimento sul posto).
* Devo tenere traccia di dove sono arrivato e prendere dal primo degli elementi 
* non ancora esaminati/spostati fino all’ultimo
 */
void insertion_sort(TInfo a[], int n)
{
    int i;
    for(i=1; i<n; i++) // i rappresenta il numero di elementi che compongono la parte già ordinata: 
		                // vale 1 alla prima iterazione
				 // (parto dal secondo elemento) ed n a fine ciclo
	{
// come argomenti passiamo ad insert_in_order, oltre all'array
// il numero di elementi del segmento di array già ordinato in cui faremo l'inserimento
// l'elemento i-esimo - il primo fuori dal segmento ordinato -  
// da confrontare e da mantenere in memoria
        	insert_in_order(a, i, a[i]);
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
//	vet[4]=25;
//	vet[5]=3;
//	vet[6]=44;
//	vet[7]=12;
//	vet[8]=9;
//	vet[9]=30;
	
	printf(" array originario : ");
	for (cont=0; cont<ARRAY_MAX; cont++)
	{
		printf("%d ", vet[cont]);
	}
	printf("\n");
	insertion_sort(vet, ARRAY_MAX);
}
