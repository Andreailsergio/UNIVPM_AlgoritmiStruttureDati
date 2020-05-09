/* Ricorsione annidata - funzione di Ackermann
*	dati due numeri positivi
*	A(m,n) = n+1				se m=0
*	A(m,n) = A(m-1,n)			se m>0 e n=0
*	A(m,n) = A(m-1,A(m,n-1))		se m>0 e n>0
*
* 	NOTA -> la funzione cresce molto rapidamente: già con A(4,1) si può avere stack overflow !
 */

#include <stdio.h>

int ackermann(int m, int n)  
{
	if (m < 0 || n < 0)
		return -1;   /* la funzione non è definita per numeri negativi ! */
	
	if (m == 0)
		return n+1;
	else
		if (n == 0)
			return ackermann(m-1, 1);
		else
			return ackermann(m-1, ackermann(m, n-1));
}

void stampaRisultato(int M, int N)
{
		printf("la funzione A(%d, %d) da come risultato %u\n", M, N, ackermann(M,N));
}

int main()
{
	stampaRisultato(0,1);
	stampaRisultato(1,0);
	stampaRisultato(2,0);
	stampaRisultato(1,1);
	stampaRisultato(2,2);
	stampaRisultato(3,1);

	stampaRisultato(4,1);  /* stack overflow */
}
