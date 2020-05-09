#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXT (25)
#define NOT_FOUND (-1)
/*
* Utilizzo la funzione strcmp (string compare) che restituisce :
*	- un valore negativo se il primo elemento di comparazione è più piccolo == viene prima
*	- zero se sono identici
*	- un valore positivo se il primo elemento è più grande == viene dopo
*/
bool binary_search_recursive(int sinistra, int destra, char* a[], char* s)
{
    bool trovato;
	printf("sinistra %d [%s]", sinistra, a[sinistra]);
	printf("- destra %d [%s]\n\n", destra, a[destra]);
    if (sinistra > destra)        //(1)
    //all'inizio sinistra==0 e quindi questo passo cattura anche il caso di vettore vuoto
    { 
		trovato = false; // NOT_FOUND
		printf("l'animale %s non e' in elenco\n\n", s);
	}
    else
	{
		int m = (destra+sinistra)/2;
        if (strcmp(a[m], s) == 0)
		{
        	trovato= true;         //(2)
		   	printf("l'animale %s e' in elenco in posizione %d (indice %d)\n\n", s, m+1, m);
		}
        else if (strcmp(a[m], s) < 0) // se a[m] viene prima proseguo con ricorsione a destra
            trovato= binary_search_recursive(m+1, destra, a, s);  // (3)
        else
            trovato= binary_search_recursive(sinistra, m-1, a, s);  //(4)
    }
	return trovato;
}  


int main(int argc, char* argv[])
{
	/* inizializzo a zero le variabili sinistra e destra */
	int sx=0;
	int dx=MAXT-1;
	int i;
	/* definizione vettore struct e suo riempimento con sequenza ordinata di dati */
	char* elenco[MAXT];
	elenco[0]="airone";
	elenco[1]="barbagianni";
	elenco[2]="cane";
	elenco[3]="dromedario";
	elenco[4]="elefante";
	elenco[5]="farfalla";
	elenco[6]="fenicottero";
	elenco[7]="gatto";
	elenco[8]="istrice";
	elenco[9]="lontra";
	elenco[10]="lumaca";
	elenco[11]="mucca";
	elenco[12]="nutria";
	elenco[13]="oca";
	elenco[14]="ornitorinco";
	elenco[15]="pantera";
	elenco[16]="pollo";
	elenco[17]="rana";
	elenco[18]="salamandra";
	elenco[19]="sardina";
	elenco[20]="tarantola";
	elenco[21]="toro";
	elenco[22]="upupa";
	elenco[23]="vespa";
	elenco[24]="zanzara";

	for (i=0;i<MAXT;i++)
			printf("%s - ", elenco[i]);
	printf("\n\n");

	//printf("cerco SARDINA\n\n");
	//binary_search_recursive(sx, dx, elenco, "sardina");
	// E' IL 20^ RECORD con indice 19

	printf("cerco TIGRE\n\n");
	binary_search_recursive(sx, dx, elenco, "tigre");
	// PROVARE CON UN NOME CHE NON ESISTE
	//"tigre"
	return 0;
}
