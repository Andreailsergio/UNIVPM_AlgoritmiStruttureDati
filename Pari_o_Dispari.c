/* Mutua Ricorsione - n è pari o dispari ? */

#include <stdio.h>

/* ritorna 1 se n è dispari, altrimenti 0 (false) 
es 2
pari(2) -> dispari(1) -> !pari(1) -> !dispari(0) -> !!pari(0) ==1 (pari)
es 3
pari(3) -> dispari(2) -> !pari(2) -> !dispari(1) -> !!pari(1) -> pari(1) -> dispari(0) -> !pari(0) <>1 (dispari)
*/
int dispari(int n)  
{
		//printf("daFdispari%d\n", n);
		return (!pari(n));
}

/* ritorna 1 se n è pari, altrimenti 0 (false) */
int pari(int n)  
{
	//printf("da Fpari:%d\n", n);
	if (n==0)
		return 1;
	else
		return (dispari(n-1));
}

void stampaRisultato(int Num)
{
	if (pari(Num)==1)
		printf("%d e' pari\n", Num);
	else
		printf("%d e' dispari\n", Num);
}

int main()
{
	stampaRisultato(9);
}
