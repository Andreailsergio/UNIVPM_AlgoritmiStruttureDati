#include <stdio.h>
#include <stdlib.h>	// libreria che contiene funzioni per l'allocazione dinamica della memoria (<malloc.h> non è standard)

typedef int TInfo;  /* definizione tipo TInfo intero */
struct SNode	  /* struttura componenti dei nodi della lista */
{
    TInfo info;			// elemento informativo
    struct SNode *link;	// elemento puntatore al successivo nodo
};
typedef struct SNode TNode; /* definisco il tipo TNode - singolo elemento della lista */
/* definisco il tipo TList come tipo riferimento * al tipo nodo generico TNode
   - sintassi derivata dal fatto che posso identificare la lista col riferimento alla sua testa */
typedef TNode *TList;


TList list_create()
{
   TNode *new, *punt;	//  new è il puntatore al primo elemento della lista, mentre punt è un puntatore ausiliario che permette di 
	                                    // scorrere la lista in modo sequenziale grazie ai collegamenti o link
   int i, n;					//  i è l'indice del ciclo, mentre n serve a memorizzare il numero degli elementi che si intende inserire
   printf("\n Specificare il numero di elementi... ");
   scanf("%d", & n);			// chiedo il numero n di elementi della lista (da tastiera)
   if(n==0)
   {
      new = NULL; // lista vuota
   }
   else
   {
      /* creazione primo elemento --- inserimento in TESTA */
      // alloco un blocco di memoria di dimensione TNode ed assegno alla variabile new il puntatore a tale blocco
      new = (TNode *)malloc(sizeof(TNode)); 
     // malloc può restituire il puntatore nullo se la memoria non è sufficiente (o se è stato richiesto un blocco di 0 bytes)
     // ---> (il valore di ritorno va controllato sempre)
      if (new==NULL)	
	{
	    printf("\n\n E R R O R E   D I   A L L O C A Z I O N E   D E L L A   M E M O R I A\n\n");
           return NULL; 
	// -> in tal caso la funzione termina --- potremmo sostituire questo IF con assert(new != NULL); 
	// che stampa un messaggio di errore e termina l'esecuzione se la condizione non è verificata
	}
      printf("\n Inserisci il primo valore: ");
      scanf("%d", & new->info);
      punt = new;   // inizializzo il puntatore ausiliario al primo nodo (TESTA)
      /* creazione elementi successivi --- inserimento in posizione centrale o in CODA */
      for(i=2; i<=n; i++)
      {
         punt->link = (TNode *)malloc(sizeof(TNode));	// alloco la memoria per creare un altro elemento della lista, identificato da punt->link
         punt = punt->link;				// il puntatore ausiliario viene fatto puntare al successivo nodo (l'oggetto da lui puntato) grazie al link
         printf("\n Inserisci il %d elemento: ", i);
         scanf("%d", & punt->info);
      } // chiudo il for
      punt->link = NULL; // marcatore fine lista -> il link dell'ultimo elemento (CODA) punta a NULL
   } // chiudo l'if-else
   return new;
} // chiudo la funzione restituendo il puntatore alla testa


// ################## --- PROCEDURA ITERATIVA
// Visita la lista list dalla testa alla coda stampando gli elementi 
// PRE: nessuna
void list_print(TList list)
{
// ciclo di scansione non predeterminato: 
// se la lista non è vuota (altrimenti list == NULL fin dall'inizio) --> percorro tutti gli elementi dalla testa alla coda -->
// quando sono alla fine il puntatore list (link al successivo elemento) è NULL e il ciclo termina
   while(list != NULL) 
   {
      printf("%d", list->info); // visualizza l'informazione su schermo
      printf(" ---> ");
      list = list->link; // scorre di un elemento (come in list_create punto al nodo successivo grazie al link)
   }
   printf("\n\n");
} 
// ##################


// ################## --- PROCEDURA RICORSIVA
// Visita la lista list dalla testa alla coda stampando gli elementi 
// PRE: nessuna
void list_print_rec(TList list)
{
    if (list != NULL)    // non stampo se la lista è vuota o se sono arrivato alla coda (list->link punta a NULL)
    {
      printf("%d", list->info); // visualizza l'informazione su schermo
      printf(" ---> ");
      list_print_rec(list->link); // chiamata ricorsiva alla funzione passando il puntamento all'elemento successivo
    }
}
// ##################



int main()
{
   TList lista; // definisce la lista
   lista = list_create(); // crea la lista
   printf("\n lista ---> ");
   list_print(lista); // stampa la lista
   list_print_rec(lista); // stampa la lista in modo ricorsivo
   printf("\n\n");
}
