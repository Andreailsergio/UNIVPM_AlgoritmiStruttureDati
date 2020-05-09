/* Ricorsione lineare - calcolo fattoriale di n */

#include <stdio.h>

long factorial(int n)  
{
	if (n==0)
		return 1;
	else
		return factorial(n-1)*n;
}

void stampaRisultato(int NF)
{
	printf("Fattoriale di %d : %d \n",NF,factorial(NF));
}

int main()
{
	stampaRisultato(4);
}
