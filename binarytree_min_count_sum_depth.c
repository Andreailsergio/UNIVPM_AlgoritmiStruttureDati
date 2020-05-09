// ALBERI BINARI DI RICERCA
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>	// libreria che contiene funzioni per l'allocazione dinamica della memoria (<malloc.h> non è standard)
#include <assert.h>

// DEFINISCO TIPI
typedef int TInfo;
struct SNode {
    TInfo info;
    struct SNode *right;
    struct SNode *left;
};
typedef struct SNode TNode;
typedef TNode *TBinaryTree;

// DEFINISCO PROTOTYPES DELLE FUNZIONI

/* Inserisce l'elemento di valore info nell'albero binario, 
 * preservando l'ordinamento; restituisce l'albero binario risultante.
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; inoltre se l'elemento da 
 *       inserire e' gia' presente, esso viene duplicato.
 */
TBinaryTree binarytree_insert(TBinaryTree bt, TInfo info);

/* Visita l'albero binario in ordine
 * PRE: nessuna
*/
void binarytree_visit(TBinaryTree bt);

// FUNZIONE GREATER
bool greater(TInfo a, TInfo b)  /* a segue b */
{
return a > b;
}

// CREA ALBERO
/* Crea e restituisce un albero binario vuoto
 * PRE: nessuna
 */
TBinaryTree binarytree_create()
{
    return NULL;
}

//CREA NODO
/* Crea ed alloca un nodo
 * PRE: nessuna
 */
TNode *node_create(TInfo info){
    TNode *new;
   new=(TNode *) malloc(sizeof(TNode));
   if (new==NULL)
      return NULL;
   new->info = info;						// creo un nodo foglia (sottoalberi destro e sinistro vuoti -> puntatore a NULL)
   new->left = NULL;
   new->right = NULL;
   return new;
}

// INSERISCI NODI - ricorsiva
/* Inserisce l'elemento di valore info nell'albero binario, preservando l'ordinamento;
 * la ricorsione decompone l'albero considerando l'elemento corrente come radice e lavorando con i suoi sottoalberi sinistro e destro
 * non modifica la struttura pre-esistente: 
 * aggiunge una foglia all'ultimo livello (e non considera altre posizioni centrali possibili) rispettando la proprietà di ordinamento
 * restituisce l'albero binario risultante.
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; inoltre se l'elemento da
 *       inserire e' gia' presente, esso viene duplicato.
 */
TBinaryTree binarytree_insert(TBinaryTree bt, TInfo info){
    /*Caso base: Albero vuoto*/
    if (bt == NULL) {
        TNode *new;
        new = node_create(info);
        if (new == NULL) {
            printf("Errore di allocazione della memoria\n");
            exit(1);
        }
        return new;
    }
        // se il valore non è maggiore lavoro con il sottoalbero di sinistra: chiamata ricorsiva finchè non trovo il sottoalbero vuoto   
	else if (!greater(info, bt->info))
    {
        /*Fase di divide at impera*/
        // aggiorno il puntatore left dell'elemento "radice corrente" - il padre - riferendolo al nuovo nodo - il figlio - del sottoalbero sinistro 
	 // che conterrà il valore info da inserire
        bt->left = binarytree_insert(bt->left, info);

        /*Fase di combina*/
        return bt;
    }
        // se il valore è maggiore-uguale lavoro con il sottoalbero di destra: chiamata ricorsiva finchè non trovo il sottoalbero vuoto   
	else 
   {		
        /*Fase di divide at impera*/
        // aggiorno il puntatore right dell'elemento "radice corrente" - il padre - riferendolo al nuovo nodo - il figlio - del sottoalbero destro
	 // che conterrà il valore info da inserire
        bt->right = binarytree_insert(bt->right, info);		

        /*Fase di combina*/
        return bt;
    }
}

//CERCA IL MINIMO
// cerco il nodo left-most (il più a sinistra possibile): ovvero quello che non possiede un sottoalbero sinistro ed è il figlio sinistro del proprio padre
// PRE: l'albero dev'essere ordinato
TNode* binarytree_min(TBinaryTree bt) {
    /*Caso base: Albero vuoto*/
    if (bt == NULL)
        return NULL;	// se l'albero è vuoto il minimo non esiste  -> restituisco NULL
    else if (bt->left == NULL)
		return bt;      // se l'albero corrente non ha il sottoalbero sinistro -> ho trovato il minimo e non devo più fare altre decomposizioni ricorsive
    else{
        /*Fase di divide at impera*/
        TBinaryTree min = binarytree_min(bt->left);	// altrimenti continuo la ricerca nel sottoalbero di sinistra (finchè non riconduco al caso base)
        
        /*Fase di combina*/
        return min;
    }
}

// CALCOLA ALTEZZA
/* PRE: l'albero non e' vuoto 
 */
int binarytree_depth(TBinaryTree tree) { 
  assert(tree!=NULL);										// controllo che l'albero in input non sia vuoto

  /* Caso base: foglia */
  if (tree->left==NULL && tree->right==NULL)
    return 0;	// se i puntatori a left e right sono entrambi null ho trovato una foglia -> arresto la ricorsione
  else if (tree->left==NULL) /* Solo sottoalbero destro */
    return 1+binarytree_depth(tree->right); // se c'è solo sottoalbero destro continuo ricorsione fino al caso base (foglia) incrementando di 1 l'altezza
  else if (tree->right==NULL) /* Solo sottoalbero sinistro */	
    return 1+binarytree_depth(tree->left); // analogamente se c'è solo sottoalbero sinistro continuo ricorsione fino a caso base + incremento di 1 altezza
  else {   /* Nodo completo */					    // se il nodo è completo (ha entrambi i sottoalberi)
      /* Fase di divide et impera */
      int depth_left=binarytree_depth(tree->left);	   // proseguo la ricorsione su entrambi i rami, 
      int depth_right=binarytree_depth(tree->right);  // memorizzando l'altezza parziale su due distinte variabili depth_left e depth_right
      /* Fase di combina */
      if (depth_left>depth_right)					   // l'altezza è la maggiore tra depth_left e depth_right (aggiungo 1 per tenere conto della radice)
          return 1+depth_left;
      else
          return 1+depth_right;
  }
}

/* INIZIO operazioni di accumulazione */
// SOMMA VALORI DEI NODI
int binarytree_sum_nodes(TBinaryTree bt){
    int sum_left, sum_right;							// inizializzo le variabili (somma valori sottoalberi sx e dx)
    /*Caso base: Albero vuoto*/
    if (bt==NULL)									// quando trovo l'albero vuoto (fin dall'inizio o come risultato delle decomposizioni successive) termino
        return 0;
        
    /*Fase di divide at impera*/
    sum_left = binarytree_sum_nodes(bt->left);		// lancio ricorsione memorizzando il risultato parziale della somma su rami a sx
    
    /*Fase di divide at impera*/
    sum_right = binarytree_sum_nodes(bt->right);	// lancio ricorsione memorizzando il risultato parziale della somma su rami a dx
    
    /*Fase di combina*/
    return bt->info+sum_left+sum_right;				// ai risultati parziali aggiungo il valore del nodo corrente
}
// CONTA LE FOGLIE
int binarytree_count_leaves(TBinaryTree bt)
{
  int count_left, count_right;											// inizializzo le variabili (numero foglie sx e dx)
  /*Caso base: Albero vuoto oppure albero con un solo elemento*/
  if(bt==NULL)	// quando trovo l'albero vuoto (fin dall'inizio -> in tal caso il risultato è 0 - degenere 
				// oppure come risultato delle decomposizioni successive) termino
    return 0;
  else if((bt->left==NULL)&&(bt->right==NULL))							// inizializzo il conteggio ad 1 in riferimento ad 1 foglia
    return 1;
  
  else{
    /*Fase di divide et impera*/
    count_left=binarytree_count_leaves(bt->left);				// lancio ricorsione memorizzando il risultato parziale del conteggio su rami sx
//printf("\n\n %d",count_left);
    /*Fase di divide et impera*/
    count_right=binarytree_count_leaves(bt->right);			// lancio ricorsione memorizzando il risultato parziale del conteggio su rami dx
//printf("\n\n %d",count_right);    
    /*Fase di combina*/
    return count_left+count_right;							// sommo i conteggi parziali ottenuti
  }
}
/* FINE operazioni di accumulazione */

/* Visita l'albero binario in ordine crescente (visita simmetrica sottoalbero sx / nodo radice / visita simmetrica sottoalbero dx)
 * divido ricorsivamente l'albero in 3 parti: il nodo corrente ("radice corrente") - il sottoalbero sx - il sottoalbero dx
 * PRE: nessuna
 */
void binarytree_visit(TBinaryTree bt){
   if (bt != NULL){						// quando l'albero è vuoto termino la ricorsione
      binarytree_visit(bt->left);			// altrimenti non sono nel caso base - visito ricorsivamente: sottoalbero sx - nodo corrente - sottoalbero dx
      printf("%d ", bt->info);				// quando stampo il nodo corrente, avendo concluso la ricorsione a sinistra, ho l'elemento più piccolo
									// poi procedo con la ricorsione sugli altri elementi
      binarytree_visit(bt->right);
    } 
}

/* Visita l'albero binario in pre-ordine (nodo radice / visita simmetrica sottoalbero sx / visita simmetrica sottoalbero dx)
 * PRE: nessuna
 */
void binarytree_visit_pre_order(TBinaryTree bt){
    if (bt != NULL){
      printf("%d ", bt->info);
      binarytree_visit_pre_order(bt->left);
      binarytree_visit_pre_order(bt->right);
    }
}

/* Visita l'albero binario in post-ordine (visita simmetrica sottoalbero sx / visita simmetrica sottoalbero dx / nodo radice)
 * PRE: nessuna
 */
void binarytree_visit_post_order(TBinaryTree bt){
    if (bt != NULL){
      binarytree_visit_post_order(bt->left);
      binarytree_visit_post_order(bt->right);
      printf("%d ", bt->info);
    }
}


// MAIN FUNCTION
int main()
{
	TInfo risultatosomma, verifica=15+7+3+33+10+25+40;
	TBinaryTree myBST= binarytree_create();

	myBST=binarytree_insert(myBST, 15); 		//		  15
	myBST=binarytree_insert(myBST, 7); 		//		7		 	  33
	myBST=binarytree_insert(myBST, 3); 	//	    3     10      25      40
	myBST=binarytree_insert(myBST, 33);                              
	myBST=binarytree_insert(myBST, 10); 
	myBST=binarytree_insert(myBST, 25);
	myBST=binarytree_insert(myBST, 40);

	printf("\n gli elementi/nodi dell'albero sono, in ordine : ");
	binarytree_visit(myBST);
	printf("\n\n");

	printf("\n gli elementi/nodi dell'albero sono, in pre-ordine : ");
	binarytree_visit_pre_order(myBST);
	printf("\n\n");

	printf("\n gli elementi/nodi dell'albero sono, in post-ordine : ");
	binarytree_visit_post_order(myBST);
	printf("\n\n");

	printf("\n conteggio delle foglie: sono %d -\n\n", binarytree_count_leaves(myBST)); // visualizza risultato conteggio foglie

	risultatosomma=binarytree_sum_nodes(myBST); // calcolo somma dei nodi
	if (risultatosomma==verifica) // se la somma dei nodi è verificata
		printf("\n somma dei nodi: risulta corretta e pari a %d -\n\n", risultatosomma); // visualizza risultato somma nodi 
	else
		printf("\n somma dei nodi: non verificata -> porta %d ma doveva portare %d \n\n", risultatosomma, verifica);

	printf("\n calcolo altezza: e' %d -\n\n", binarytree_depth(myBST)); // visualizza risultato altezza

	printf("\n cerco il minimo: e' %d -\n\n", binarytree_min(myBST)->info); // visualizza risultato minimo

	printf("\n\n");
}
