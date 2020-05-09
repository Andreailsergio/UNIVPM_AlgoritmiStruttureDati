// TABELLE HASH AD INDIRIZZAMENTO CHIUSO
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>	// libreria che contiene funzioni per l'allocazione dinamica della memoria (<malloc.h> non è standard)
#include <assert.h>

// definizione tipo TInfo per chiavi/valori associati interi
typedef struct SInfo
{
    int key;
    int value;
}TInfo;

// definizione struttura componenti dei nodi della lista
struct SNode
{
    TInfo info;			// elemento informativo (a sua volta struttura chiave, valore)
    struct SNode *link;	// elemento puntatore al successivo nodo
};

typedef struct SNode TNode;	// definisco il tipo TNode - singolo elemento della lista 
typedef TNode *TList;	// definisco il tipo TList come tipo riferimento * al tipo nodo generico TNode 
// sintassi derivata dal fatto che posso identificare la lista col riferimento alla sua testa

// definizione struttura hash table - un intero che rappresenta il numero di buckets 
// ed il vettore bucket di tipo Tlist che contiene le liste dinamiche
typedef struct SHashTable
{
    int bucket_number;
    TList *bucket;
} THashTable;

// prototipi principali operazioni sulla tabella
THashTable *hashtable_create(int buckets);
void hashtable_insert(THashTable *ht, int key, int value);
int *hashtable_search(THashTable *ht, int key);
void hashtable_print(THashTable *ht);

// funzione equal ---> confronto key (non value) - per verificare che siano unica
bool equal(TInfo a, TInfo b) {
    return a.key == b.key;
}

/* Crea e restituisce una lista vuota
 * PRE: nessuna
 */
TList list_create() {
    return NULL;
}

/* Crea ed alloca un nodo
 * PRE: nessuna
 */
TNode *node_create(TInfo info)
{
   TNode *new;

   new=(TNode *) malloc(sizeof(TNode));
   if (new==NULL)
      return NULL;
   new->info = info;
   new->link = NULL;
   return new;
}

// ### INIZIO ### RICERCA ITERATIVA ###############
/* Ricerca l'elemento di valore info nella lista list, preservando
 * l'ordinamento; restituisce la lista risultante.
 * PRE: ------------------------------------------------------------------> NESSUNA -> la list può anche non essere ordinata !!!!
 * NB Funzione richiamata sia x inserimento (verifica che non ci siano chiavi duplicate) 
 *                                            sia x ricerca (appena trovo la prima chiave lo comunico)
 */
TNode *list_search_unordered(TList list, TInfo info)
{
    TNode * curr;
    curr = list;
    
    while ((curr != NULL) && !equal(info, curr->info))   // ciclo finchè non trovo elemento (chiave già esistente) o sono alla fine  
    {
        curr = curr->link;
    }
    /* Analisi delle post-condizioni del ciclo
       ----------------------------------------> C1: raggiungo la fine della lista senza trovare l'elemento		--> curr = NULL
       ----------------------------------------> C2: elemento trovato (chiave già esistente)		--> curr = puntatore ad un nodo 										
     */
    if (curr == NULL) 
        return NULL;
    else
	/* Elemento trovato se curr non è nullo (valore da sovrascrivere se sto inserendo - valore trovato se sto cercando) */
        return curr;
}
// ### FINE ### RICERCA ITERATIVA ###############

// inserimento nella lista al primo nodo libero (IN TESTA)
TList list_insert_at_index(TList l, TInfo info)
{
	TNode *newnode;
       newnode = node_create(info);	
	if (newnode == NULL)
	{
		printf("\n\nErrore Allocazione Memoria\n\n");
		exit(1);
	}
	newnode->link = l;
	return newnode;
}

// inizializzazione tabella hash
/* PRE: buckets > 0 */
THashTable *hashtable_create(int buckets)
{
    int i;
    THashTable *p=(THashTable *)malloc(sizeof(THashTable)); // alloco memoria alla hash table associandola al puntatore p
    assert(p!=NULL);		// verifico che allocazione sia andata a buon fine
    assert(buckets>0);		// verifico la precondizione - il parametro buckets è > 0

    p->bucket_number = buckets;
    p->bucket = (TList *) malloc(sizeof(TList)*buckets);	// allocazione vettore di bucket = contenitore di liste
    assert(p->bucket!=NULL);
   
    for(i=0; i<buckets; i++)
        p->bucket[i]=list_create();	// inizializzo ciascun elemento bucket con una lista vuota

    return p;
}

// definizione FUNZIONE DI HASH per interi
unsigned hash(int key)
{
	return (unsigned) key;
}

// INSERIMENTO ELEMENTI
void hashtable_insert(THashTable *ht, int key, int value)
{
    TInfo info;
    info.key=key;
    info.value=value;
// calcolo indice hash - l'operatore resto divisione (MOD %) riconduce l'intervallo di indici validi al numero di buckets definiti 
//   (nel nostro caso 4: con valori hash 0, 1, 2, 3)
    unsigned h=hash(key) % ht->bucket_number;	

    TNode *node=list_search_unordered(ht->bucket[h], info);	// cerco se la chiave è duplicata
    if (node==NULL)											// se non lo è
    { 
// inserisco un nuovo nodo nella lista dinamica associata a quel bucket
//   non alla posizione k (come nel libro) ma in testa - la lista risultante non è ordinata
       ht->bucket[h]=list_insert_at_index(ht->bucket[h], info);
	printf("- nuovo nodo -> hash: %d\n", h);
	printf("- key: %d - value: %d \n\n", info.key, info.value);
    }
    else														// se lo è
    { 
	node->info=info;						// sovrascrivo il valore associato alla chiave (e lascio nella stessa posizione)
	printf(" -- sovrascrivo nodo -> hash: %d\n", h);
	printf(" -- key: %d - value: %d \n\n", info.key, info.value);
    }
}

// RICERCA ELEMENTO
int *hashtable_search(THashTable *ht, int key)
{
    unsigned h=hash(key) % ht->bucket_number;		// calcolo l'indice hash riferito all'elemento/chiave che sto cercando
    TInfo info;
    info.key=key;
    TNode *node=list_search_unordered(ht->bucket[h], info);	// cerco la chiave tra i nodi della lista associata
    if (node==NULL)
        return NULL;											// ritorno NULL se non ho trovato l'elemento
    else
        return &node->info.value;
	// ritorno l'indirizzo di memoria in cui è contenuto il valore VALUE associato alla chiave per cui sto cercando
}

// STAMPA TUTTI GLI ELEMENTI DELLA HASH TABLE
void hashtable_print(THashTable *ht)
{ 
    int i;
    TNode *n;
    for(i=0; i<ht->bucket_number; i++)				// il primo ciclo esterno scorre il vettore di bucket della tabella
    { 
	printf("hash: %d \n", i);
       //for(n=ht->bucket[i]; n!=NULL; n=n->link)	// x ciclare internamente potrei usare anche questa riga di istruzioni commentata
	// il ciclo interno scorre i nodi della lista associata al bucket corrente
	n=ht->bucket[i];
	while (n!=NULL)
       { 
		printf("   --- key: %d - value: %d \n", n->info.key, n->info.value);
		n=n->link;
       }
    }
}

// MAIN FUNCTION
int main()
{
	THashTable *myhashtab;
	myhashtab = hashtable_create(4); // 4 buckets

	hashtable_insert(myhashtab, 1, 1700); // elemento 01 (chiave 1 - valore 1700)
	hashtable_insert(myhashtab, 10, 1730); // elemento 02 (chiave 10 - valore 1730)
	hashtable_insert(myhashtab, 2, 1800); // elemento 03 (chiave 2 - valore 1800)
	hashtable_insert(myhashtab, 20, 1850); // elemento 04 (chiave 20 - valore 1850)
	hashtable_insert(myhashtab, 25, 1892); // elemento 05 (chiave 25 - valore 1892)
	hashtable_insert(myhashtab, 3, 1900); // elemento 06 (chiave 3 - valore 1900)
	hashtable_insert(myhashtab, 30, 1940); // elemento 07 (chiave 30 - valore 1940)
	hashtable_insert(myhashtab, 4, 2000); // elemento 08 (chiave 4 - valore 2000)
	hashtable_insert(myhashtab, 40, 2011); // elemento 09 (chiave 40 - valore 2011)
	hashtable_insert(myhashtab, 1, 2011); // elemento 09 (chiave 1 - valore 2011) // provo inserimento chiave duplicata
	hashtable_insert(myhashtab, 5, 2100); // elemento 10 (chiave 5 - valore 2100)

	printf("\n elemento trovato per la chiave %d ---> %d\n\n", 25, *hashtable_search(myhashtab, 25)); 
	// visualizza valore risultato dalla ricerca

	printf("STAMPO LA TABELLA HASH RISULTANTE\n");
	hashtable_print(myhashtab);
	printf("\n\n");
}
