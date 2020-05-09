#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>	// libreria che contiene funzioni per l'allocazione dinamica della memoria (<malloc.h> non è standard)

typedef int TInfo;  /* definizione tipo TInfo intero */
struct SNode	  /* struttura componenti dei nodi della lista */
{
    TInfo info;			// elemento informativo
    struct SNode *link;	// elemento puntatore al successivo nodo
};
typedef struct SNode TNode; /* definisco il tipo TNode - singolo elemento della lista */
/* definisco il tipo TList come tipo riferimento * al tipo nodo generico TNode 
// -> sintassi derivata dal fatto che posso identificare la lista col riferimento alla sua testa */
typedef TNode *TList;	       

bool equal(TInfo a, TInfo b)  /* a e b sono equivalenti */
{
return a == b;
}

bool greater(TInfo a, TInfo b)  /* a segue (è più grande di) b */
{
return a > b;
}

/* Distrugge e dealloca un nodo
 * PRE: nessuna
 */
void node_destroy(TNode *node) {
    free(node);
}

TList list_create()   // versione semplificata : crea LISTA ORDINATA di 6 nodi da codice --- info: 23, 36, 44, 58, 89, 99
{
   TNode *new, *punt;		
   //  new è il puntatore al primo elemento della lista, 
   // mentre punt è un puntatore ausiliario che permette di scorrere la lista in modo sequenziale grazie ai collegamenti o link
      /* creazione primo elemento --- inserimento in TESTA */
      new = (TNode *)malloc(sizeof(TNode)); // alloco un blocco di memoria di dimensione TNode ed assegno alla variabile new il puntatore a tale blocco
      if (new==NULL)	// malloc può restituire il puntatore nullo se la memoria non è sufficiente (o se è stato richiesto un blocco di 0 bytes)
		                     // ---> (il valore di ritorno va controllato sempre)
	{
	    printf("\n\n E R R O R E   D I   A L L O C A Z I O N E   D E L L A   M E M O R I A\n\n");
           return NULL;
	    // -> in tal caso la funzione termina --- potremmo sostituire questo IF con assert(new != NULL); 
	    //  che stampa un messaggio di errore e termina l'esecuzione
	}
      new->info = 23;
      punt = new;   // inizializzo il puntatore ausiliario al primo nodo (TESTA)
      
	/* creazione 2^ elemento --- inserimenti in posizione centrale */
         punt->link = (TNode *)malloc(sizeof(TNode));	// alloco la memoria per creare un altro elemento della lista, identificato da punt->link
         punt = punt->link;				// il puntatore ausiliario viene fatto puntare al successivo nodo (l'oggetto da lui puntato) grazie al link
         punt->info = 36;
	/* creazione 3^ elemento */
         punt->link = (TNode *)malloc(sizeof(TNode));	// alloco la memoria per creare un altro elemento della lista, identificato da punt->link
         punt = punt->link;				// il puntatore ausiliario viene fatto puntare al successivo nodo (l'oggetto da lui puntato) grazie al link
         punt->info = 44;
	/* creazione 4^ elemento */
         punt->link = (TNode *)malloc(sizeof(TNode));	// alloco la memoria per creare un altro elemento della lista, identificato da punt->link
         punt = punt->link;				// il puntatore ausiliario viene fatto puntare al successivo nodo (l'oggetto da lui puntato) grazie al link
         punt->info = 58;
	/* creazione 5^ elemento */
         punt->link = (TNode *)malloc(sizeof(TNode));	// alloco la memoria per creare un altro elemento della lista, identificato da punt->link
         punt = punt->link;				// il puntatore ausiliario viene fatto puntare al successivo nodo (l'oggetto da lui puntato) grazie al link
         punt->info = 89;      
	/* creazione ultimo elemento --- inserimento in CODA */
         punt->link = (TNode *)malloc(sizeof(TNode));	// alloco la memoria per creare un altro elemento della lista, identificato da punt->link
         punt = punt->link;				// il puntatore ausiliario viene fatto puntare al successivo nodo (l'oggetto da lui puntato) grazie al link
         punt->info = 99;
         punt->link = NULL; // marcatore fine lista -> il link dell'ultimo elemento (CODA) punta a NULL

   return new;
} // chiudo la funzione

// ### INIZIO ### RICERCA ITERATIVA ###############
/* Ricerca l'elemento di valore info nella lista list, preservando
 * l'ordinamento; restituisce la lista risultante.
 * PRE: list e' ordinata
 */
TNode *list_search_ordered(TList list, TInfo info)
{

    /* PRE: la lista list e' ordinata */
    TNode * curr;
    curr = list;
       //printf("%d", curr->info);
       // posizione di curr dopo il ciclo :
    /*P1: l'elemento da cercare ha un valore info inferiore a quello
     *    dell'elemento di testa della lista 															
     *P2: l'elemento da cercare ha un valore info compreso tra quello
     *    della testa e quello della coda della lista (in tal caso può comunque esistere o non esistere nella lista)	
     *P3: l'elemento da cercare ha un valore info maggiore di tutti
     *    quelli degli elementi della lista															
     */
    // il ciclo scansiona tutti i nodi passando al successivo finchè curr non è NULLO (ovvero si sono verificati i casi P1 e P3)
    // e contemporaneamente il valore cercato non è maggiore di curr->info corrente (caso P2 con dato non trovato)
    while ((curr != NULL) && (info>(curr->info))) // greater(info,curr->info))  
    {
	//printf("%d/n/n", curr->info);
        curr = curr->link;
    }

    /* Analisi delle post-condizioni del ciclo
       C1: valore da cercare piu' piccolo della Testa						--> curr = NULL
       C2: valore da cercare maggiore della Coda						--> curr = NULL
       C3: valore da cercare compreso tra quello di Testa e quello di 
           Coda															--> curr = puntatore ad un nodo
     */
    if ((curr != NULL) && equal(curr->info, info)) 
        /* Elemento trovato se curr non è nullo e se il puntatore trovato fa riferimento al valore info in esame */
        return curr;
    else
        return NULL;
}
// ### FINE ### RICERCA ITERATIVA ###############

// ### INIZIO ### CANCELLAZIONE ITERATIVA ###############
/* Cancella un elemento di valore info dalla lista list, preservando l'ordinamento
 * ed i collegamenti tra nodi; restituisce la lista risultante.
 * PRE: list e' ordinata
 * NOTA: consuma il parametro list; inoltre se l'elemento da cancellare
 *       e' duplicato cancella solo la prima occorrenza.*/
 TList list_delete(TList list, TInfo info)
{
    TNode *prec, *curr, *alias;
    prec = NULL;
    curr = list;

// postcondizioni all'uscita del ciclo :
    /*P1: curr==NULL o info!=curr->info
     *    --> l'elemento da cancellare non e' presente
     *P2: la condizione P1 non e' verificata (l'elemento esiste!) e prec==NULL
     *    --> va cancellato l'elemento di testa
     *P3: la condizione P1 non e' verificata (l'elemento esiste!), prec!=NULL e curr!=NULL
     *    --> va cancellato un elemento in posizione intermedia della lista */
     
    /* F1: ricerca dell'elemento da cancellare */
    while ((curr != NULL) && greater(info, curr->info))
    {
        prec = curr;			// prec serve x conoscere il riferimento precedente a quello da cancellare
        curr = curr->link;
    }

    /* Analisi delle post-condizioni */
    if ((curr != NULL) && equal(curr->info, info))
    {    /* Elemento trovato */

        /* F2: aggiornamento della catena dei collegamenti */
        if (prec == NULL)
	 {
            /* CASO C2: Cancellazione della Testa
			---> il nuovo elemento della testa sarà il successore del nodo da cancellare */
            list = curr->link;
        }
	 else
	 {
            /* CASO C3: Cancellazione da una posizione intermedia (vale anche nel caso della Coda, il cui nodo successivo è comunque sempre null)
			---> il nodo precedente a quello da cancellare va collegato al successore del nodo da cancellare */
            alias = curr->link;     // mantengo una copia del puntatore all'elemento successivo a quello logicamente cancellato
            prec->link = alias;	   // così riesco a far puntare il link del precedente all'elemento successore
        }

        /* F3: Deallocazione del Nodo cancellato logicamente = cancellazione fisica */
        node_destroy(curr);
        return list;
    }
    return list;
}
// ### FINE ### CANCELLAZIONE ITERATIVA ###############


// ### INIZIO ### RICERCA RICORSIVA ###############
/* Cerca l'elemento di valore info nella Lista list. Ritorna il 
 * riferimento all'elemento se e' presente, altrimenti ritorna NULL.
 * PRE: list e' ordinata
 */
TNode *list_search_recursive(TList list, TInfo info)
{

 if (list == NULL || greater(list->info, info))    // casi base : 1)  la lista è vuota   o   2) il primo elemento della lista è + grande di quello cercato
        return NULL;
 else
    {
        if (equal(list->info, info))                      // oppure  3) l'elemento cercato è proprio il primo della lista
            return list;
        else
		// se non rientro nei 3 casi base reitero basandomi su una nuova lista ottenuta togliendo il primo elemento
	 	// ... e così via fino a ricondurre ad uno dei tre casi base
            return list_search_recursive(list->link, info);
    }
}
// ### FINE ### RICERCA RICORSIVA ###############

// ### INIZIO ### CANCELLAZIONE RICORSIVA ###############
/* Cancella un elemento di valore info dalla lista list, preservando l'ordinamento
 * ed i collegamenti tra nodi; restituisce la lista risultante.
 * PRE: list e' ordinata
 * NOTA: consuma il parametro list; se l'elemento da cancellare non
      e' presente, la lista resta inalterata.
 */
TList list_delete_recursive(TList list, TInfo info)
{
    if (list == NULL || greater(list->info, info))
	// casi base di NON cancellazione (perchè non ho trovato elemento) 1) lista vuota o 2) primo elemento della lista più grande del valore cercato
	{
	 //printf("casi base NULL\n\n");
        return NULL;
	 }
    else
    {
         if (equal(list->info, info))				// caso base di cancellazione 3) cancellazione in testa - prima logica (con alias) poi fisica
	  { /* cancellazione in testa */
	     //printf("caso base CANC. TESTA\n\n");
            TNode *alias = list->link;
            node_destroy(list);
	     //printf("CT - %d\n\n", list->info);
            return alias;
         }
         else
	  {
            TList l2;			// finchè non rientro nei casi base reitero con una nuova lista l2 con 1 nodo in meno
	     //printf("caso base REITERO\n\n");
	     //printf("R - %d\n\n", list->info);
            l2 = list_delete_recursive(list->link, info);
            list->link = l2;
            return list;
         }
    }
}
// ### FINE ### CANCELLAZIONE RICORSIVA ###############

// ################## --- PROCEDURA RICORSIVA STAMPA
// Visita la lista list dalla testa alla coda stampando gli elementi 
// PRE: nessuna
void list_print(TList list)
{
    if (list != NULL)    // non stampo se la lista è vuota o se sono arrivato alla coda (list->link punta a NULL)
    {
      printf("%d", list->info); // visualizza l'informazione su schermo
      printf(" ---> ");
      list_print(list->link); // chiamata ricorsiva alla funzione passando il puntamento all'elemento successivo
    }
}
// ##################

int main()
{
   TList lista; // definisce la lista
   lista = list_create(); // crea la lista -> versione semplificata : crea LISTA ORDINATA di 6 nodi da codice --- info: 23, 36, 44, 58, 89, 99
   printf("\n lista INIZIALE : ");
   list_print(lista); // stampa la lista INIZIALE
   printf("\n\n");
   printf("\n cerco 99 con iterazione -> \n\n");
   if (list_search_ordered(lista, 99) != NULL)
   	printf("\n elemento trovato ! \n\n");
   else
   	printf("\n elemento NON trovato ! \n\n");
   lista=list_delete(lista, 44);
   printf("\n DOPO CANCELLAZIONE ITERATIVA DI 44 : ");
   list_print(lista); // stampa la lista senza 44
   printf("\n\n");
   printf("\n cerco 44 con ricorsione -> \n\n");
   if (list_search_recursive(lista, 44) != NULL)
   	printf("\n elemento trovato ! \n\n");
   else
   	printf("\n elemento NON trovato ! \n\n");
   lista=list_delete_recursive(lista, 99);
   // list_delete_recursive(lista, 101);
   printf("\n DOPO CANCELLAZIONE RICORSIVA DI 99 : ");
   list_print(lista); // stampa la lista senza 99
   printf("\n\n");
}
