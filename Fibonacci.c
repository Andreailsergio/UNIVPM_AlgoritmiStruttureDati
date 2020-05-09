/* Ricorsione multipla (binaria o doppia) - la successione di Fibonacci - calcola ultimo valore della successione di argomento n */

#include <stdio.h>

long fibonacci(long n)  
{
	/* casi base */
	if (n==0 || n==1)
		return n;
	else
	/* fasi divide, impera, combina */
		return fibonacci(n-1) + fibonacci(n-2);
}

void stampaRisultato(long N)
{
	printf("Risultato sequenza Fibonacci - dopo %u mesi nasceranno %u coppie di conigli\n",N,fibonacci(N));
}

int main()
{
	stampaRisultato(10);
}
