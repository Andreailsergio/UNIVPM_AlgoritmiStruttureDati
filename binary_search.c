
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXT (25)
#define NOT_FOUND (-1)

/* definizione tipo TInfo per rappresentare persone e numeri telefonici
*  (la relazione di ordine si assume crescente di cognome e a parità di nome)
*  elemento strutturato -> collezione di campi */
typedef struct   
{
	char* cognome;
	char* nome;
	char* telefono;
} TInfo;

/*
* Utilizzo la funzione strcmp (string compare) che restituisce :
*	- un valore negativo se il primo elemento di comparazione è più piccolo == viene prima
*	- zero se sono identici
*	- un valore positivo se il primo elemento è più grande == viene dopo
*
*
*/
bool equal(char* cog, char* nom, char* b0, char* b1)  /* a e b sono equivalenti */
{
	return strcmp(nom, b1)==0 &&
		strcmp(cog, b0)==0;
}

bool less(char* cog, char* nom, char* b0, char* b1)  /* a precede b */
{
	int conf_cognomi;
	conf_cognomi=strcmp(cog, b0);  /* confronta stringhe */
	if (conf_cognomi<0)
		return true;
	else if (conf_cognomi==0)
		return strcmp(nom, b1)<0;
	else  /* conf_cognomi > 0 */
		return false;
}

/* Ricerca dicotomica.
 * Restituisce l'indice di un elemento di a che sia equal a x,
 * o un valore negativo se l'elemento non viene trovato.
 * PRE: l'array struct a e' ordinato per cognome - nome rispetto alla relazione less
 */
int binary_search(TInfo a[MAXT], char* x0, char* x1)
{
	int first=0;
	int last=MAXT-1;
	int chosen=(first+last)/2;

	printf("stai cercando %s %s \n\n", x0, x1);

	while (first <= last)
	{
		printf("--- first %d --- chosen %d --- last %d", first, chosen, last);
		getchar();
 		if (equal(a[chosen].cognome, a[chosen].nome, x0, x1))
			{
				printf("%s %s (%d) --- EQUAL --- %s %s (11)", a[chosen].cognome, a[chosen].nome, chosen, x0, x1);
				getchar();
				printf("il numero di %s %s e' : %s\n\n", x0, x1, a[chosen].telefono);
				return chosen;
			}
		else if (less(a[chosen].cognome, a[chosen].nome, x0, x1)) 
		// se nome-cognome scelto viene prima di nome-cognome cercato continuerò a cercare nel segmento a destra
			{
				printf("%s %s (%d) --- LESS --- %s %s (11)", a[chosen].cognome, a[chosen].nome, chosen, x0, x1);
				getchar();
				first=chosen+1;
			}
		else 
		// se nome-cognome scelto viene dopo dovrò continuare a cercare nel segmento a sinistra
			{
				printf("%s %s (%d) --- GREATER --- %s %s (11)", a[chosen].cognome, a[chosen].nome, chosen, x0, x1);
				getchar();
				last=chosen-1;
			}
		chosen=(first+last)/2;
	}
	printf("il numero di %s %s non e' in elenco\n\n", x0, x1);
	return NOT_FOUND;
}

int main(int argc, char* argv[])
{
	/* definizione vettore struct e suo riempimento con sequenza ordinata di dati */
	TInfo elenco[MAXT];
	elenco[0].cognome="andreani";
	elenco[0].nome="andrea";
	elenco[0].telefono="07111111";
	elenco[1].cognome="barbareschi";
	elenco[1].nome="barbara";
	elenco[1].telefono="07122222";
	elenco[2].cognome="carletti";
	elenco[2].nome="carlo";
	elenco[2].telefono="07133333";
	elenco[3].cognome="danielini";
	elenco[3].nome="daniele";
	elenco[3].telefono="07144444";
	elenco[4].cognome="eletti";
	elenco[4].nome="elena";
	elenco[4].telefono="07155555";
	elenco[5].cognome="fabi";
	elenco[5].nome="fabio";
	elenco[5].telefono="07166666";
	elenco[6].cognome="fiori";
	elenco[6].nome="fiorello";
	elenco[6].telefono="07177777";
	elenco[7].cognome="gennaretti";
	elenco[7].nome="gennaro";
	elenco[7].telefono="07188888";
	elenco[8].cognome="ilari";
	elenco[8].nome="ilario";
	elenco[8].telefono="07199999";
	elenco[9].cognome="loreto";
	elenco[9].nome="lorella";
	elenco[9].telefono="07112345";
	elenco[10].cognome="lucidi";
	elenco[10].nome="lucio";
	elenco[10].telefono="07123456";
	elenco[11].cognome="manuli";
	elenco[11].nome="manuela";
	elenco[11].telefono="07134567";
	elenco[12].cognome="nadini";
	elenco[12].nome="nadia";
	elenco[12].telefono="07145678";
	elenco[13].cognome="nucci";
	elenco[13].nome="nuccio";
	elenco[13].telefono="07156789";
	elenco[14].cognome="osvaldi";
	elenco[14].nome="osvaldo";
	elenco[14].telefono="07167890";
	elenco[15].cognome="poli";
	elenco[15].nome="paola";
	elenco[15].telefono="07178901";
	elenco[16].cognome="polli";
	elenco[16].nome="patrizio";
	elenco[16].telefono="07189012";
	elenco[17].cognome="ranieri";
	elenco[17].nome="raniero";
	elenco[17].telefono="07190123";
	elenco[18].cognome="rodolfini";
	elenco[18].nome="rodolfo";
	elenco[18].telefono="07122555";
	elenco[19].cognome="silvi";
	elenco[19].nome="silvia";
	elenco[19].telefono="07111333";
	elenco[20].cognome="tinelli";
	elenco[20].nome="tino";
	elenco[20].telefono="07133444";
	elenco[21].cognome="ughi";
	elenco[21].nome="ugo";
	elenco[21].telefono="07155777";
	elenco[22].cognome="valori";
	elenco[22].nome="valeria";
	elenco[22].telefono="07188999";
	elenco[23].cognome="zanetti";
	elenco[23].nome="zeno";
	elenco[23].telefono="07177666";
	elenco[24].cognome="zori";
	elenco[24].nome="zorro";
	elenco[24].telefono="07144111";
	
	binary_search(elenco, "manuli", "manuela");
	// E' IL 12^ RECORD con indice 11
	//"manuli", "manuela"

	// E' IL 20^ RECORD con indice 19
	//"silvi", "silvia"

	// PROVARE CON UN NOME CHE NON ESISTE
	//"rossi", "paolo"
	return 0;
}
