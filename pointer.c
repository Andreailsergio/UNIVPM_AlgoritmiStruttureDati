/* pointer.c
illustra l'utilizzo dei puntatori */
#include <stdio.h>
int main()
{
int b,c; /* definisco 2 interi */
int *a; /* definisco a come puntatore a intero */
b=10; /* assegno a b il valore 10 */
a=&b; /* assegno ad a l'indirizzo di memoria di b (000000bbff0ff8a4) */
c=*a; /* assegno a c il valore contenuto all'indirizzo di memoria specificato da a
		-> siccome a contiene l'indirizzo in memoria di b c sara' uguale a b */
printf("variabile int -> b = %d\n\n",b);
printf("puntatore int* all'indirizzo di memoria di b -> a = %p\n\n",a);	// notare la stampa con %p anzichè %d
printf("variabile che assume il valore all'indirizzo di memoria a,\n ovvero il valore di b -> c = %d\n\n",c);
return 0;
}
