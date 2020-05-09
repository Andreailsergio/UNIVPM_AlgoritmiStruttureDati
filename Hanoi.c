/* Torre di Hanoi - n dischi - 3 pioli (O=origine, I=intermedio, D=destinazione) */

#include <stdio.h>

void hanoi(int n, int O, int D, int I)  
{
	if (n==1)
		printf("\nSposto il disco da: %d a: %d\n", O, D);	// caso base: sposto 1 solo disco tra 2 pioli
	else						// agisco decomponendo ricorsivamente il problema con n dischi a problemi più semplici con n-1 dischi (fino al caso base con 1 disco/2 pioli)
		{
			hanoi(n-1, O, I, D);
			hanoi(1, O, D, I);
			hanoi(n-1, I, D, O);
		}
}

int main()
{
	hanoi(4, 1, 3, 2);		// parametri: numero dischi (4) - piolo di origine (1) - piolo di destinazione (3) - piolo intermedio (2)
}
