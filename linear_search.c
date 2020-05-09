#include <stdbool.h>
#include <stdio.h>

#define ARRAY_MAX 10
#define NOT_FOUND (-1)

bool equal(int a, int b)  /* a e b sono equivalenti */
{
	return a == b;
}
/* Ricerca lineare: Restituisce e stampa l'indice di un elemento del vettore a[] che sia equal a x,
	o restituisce un valore negativo se l'elemento non viene trovato */
int linear_search(int a[], int x)
{
	int i=0;
	while (i<ARRAY_MAX && !equal(a[i], x))
		i++;

	if (i<ARRAY_MAX)
	{
		printf("il numero %d e' nell'array alla posizione %d\n", x, i+1);
		return i;
	}
	else
	{
		printf("il numero %d non è presente nell'array\n", x);
		return NOT_FOUND;
	}
}

int main()
{
	/* definizione vettore monodimensionale e suo riempimento con sequenza di numeri interi */
	int vet[ARRAY_MAX];
	vet[0]=12;
	vet[1]=1;
	vet[2]=8;
	vet[3]=17;
	vet[4]=25;
	vet[5]=3;
	vet[6]=44;
	vet[7]=16;
	vet[8]=9;
	vet[9]=30;
	linear_search(vet, 44);
}

