/* Metodo iterativo - calcolo fattoriale di n */

#include <stdio.h>

long factorial(int n)  
{
	int i;
	int prodotto = 1;
	for (i=1; i<n+1; i++)
			prodotto=prodotto*i;
	return prodotto;
}

void stampaRisultato(int NF)
{
	printf("Fattoriale di %d : %d \n",NF,factorial(NF));
}

int main()
{
	stampaRisultato(4);
}
