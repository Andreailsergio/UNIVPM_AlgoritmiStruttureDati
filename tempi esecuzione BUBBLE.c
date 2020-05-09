#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


typedef int TInfo;

// struttura/tipo di Singly Linked List
typedef struct SNode {
    TInfo info;
    struct SNode* link;
} TNode;

typedef TNode* TList;


// inserimento in TESTA - su lista dinamica singly linked
TList aggiungi_in_testaSINGLY(TList l, int nuovo_valore)
{
    TNode* nuovo_nodo = (TNode *)malloc(sizeof(TNode));
    nuovo_nodo->info = nuovo_valore;
    nuovo_nodo->link = NULL;

    if(l == NULL) {
        return nuovo_nodo;
    }

	nuovo_nodo->link = l;
	return nuovo_nodo;
}


void stampa_lista(TList l)
{
    while(l != NULL) {
        printf("%d  ", l->info);
        l = l->link;
    }
    printf("\n");
}

// INVERTI LA LISTA (ALGORITMO RICORSIVO)
TList list_reverse_recu(TList list)
{
   if (list==NULL)
      return NULL;
   else {
      TList rev_coda = list_reverse_recu(list->link);
      list->link = NULL;
      if(rev_coda!=NULL){
        TList curr = rev_coda;
        while(curr->link!=NULL)
          curr = curr->link;
        curr->link = list;
        return rev_coda;
      }
      else
        return list;
      }
}

// ORDINAMENTO LISTA CON BUBBLE SORT
// void bubble_sort_lista(TList *lista)
// {
//     int temp;
//     int modified = 1;
//     TNode* l1 = NULL;
//     TNode* l2 = NULL;
// 
//     while(modified == 1) {
//         modified = 0;
//         for(l1 = *lista; l1->link != NULL; l1 = l1->link) {
//             for(l2 = l1->link; l2 != NULL; l2 = l2->link) {
//                 if(l1->info > l2->info) {
//                     temp = l1->info;
//                     l1->info = l2->info;
//                     l2->info = temp;
//                     modified = 1;
//                 }
//             }
//         }
//     }
// }

// ORDINAMENTO BUBBLE
TNode* bubble_sort_lista(TNode* l)
{
    if ( !l && !l->link) return l;
    
    bool modified;
    TNode* bubble;
	
    do
    {
        modified = 0;
        
        //il primo è speciale
        if ( l->info > l->link->info )
        {
            modified =! modified;
            //tolgo dalla lista il secondo elemento
            bubble = l->link;
            l->link = bubble->link;
            //metto l'elemento tolto in testa alla lista
            bubble->link = l;
            l = bubble;
        }
        //tutti gli altri confronto il successivo con il successivo successivo
        //in questo modo non perdo il riferimento al precedente
        for(bubble = l; bubble->link->link; bubble = bubble->link) 
        {
            if ( bubble->link->info > bubble->link->link->info )
            {
                if ( !modified ) modified =! modified;
				
                //tolgo dalla lista l'elemento sucessivosucessivo
                TNode* swap = bubble->link->link;
                bubble->link->link = swap->link;
                //swappo
                swap->link = bubble->link;
                bubble->link = swap;
            }       
        }
    }while(modified);
    
    return l;
}

// COPIA LA LISTA RICORSIVAMENTE
TList list_copy_recu(TList list) {
  if (list==NULL)
    return NULL;
  else {
    TList copia_coda = list_copy_recu(list->link);
    TList tmp = (TNode *) malloc (sizeof(TNode));
    if(tmp==NULL) {
      printf("Errore di allocazione della memoria\n");
      exit(1);
    }
    tmp->info = list->info;
    tmp->link = copia_coda;
    return tmp;
  }
}

void main()
{
	// USING CLOCK()
	double time_spent;
	clock_t begin, end;
	int cont;
	
	TList listaTS=NULL, listaTS_ORD=NULL, listaTS_INV=NULL, listaTS_COP=NULL, listaTS_ORD_COP=NULL, listaTS_INV_COP=NULL, listaRIS1=NULL, listaRIS2=NULL, listaRIS3=NULL;

	printf("\n");

// INIZIO INSERIMENTO IN TESTA

listaTS=aggiungi_in_testaSINGLY(listaTS, 7321);
listaTS=aggiungi_in_testaSINGLY(listaTS, 10);
listaTS=aggiungi_in_testaSINGLY(listaTS, 3);
listaTS=aggiungi_in_testaSINGLY(listaTS, 267);
listaTS=aggiungi_in_testaSINGLY(listaTS, 54);
listaTS=aggiungi_in_testaSINGLY(listaTS, 3421);
listaTS=aggiungi_in_testaSINGLY(listaTS, 24);
listaTS=aggiungi_in_testaSINGLY(listaTS, 2394);
listaTS=aggiungi_in_testaSINGLY(listaTS, 782);
listaTS=aggiungi_in_testaSINGLY(listaTS, 1);
listaTS=aggiungi_in_testaSINGLY(listaTS, 8843);
listaTS=aggiungi_in_testaSINGLY(listaTS, 23);
listaTS=aggiungi_in_testaSINGLY(listaTS, 5250);
listaTS=aggiungi_in_testaSINGLY(listaTS, 59);
listaTS=aggiungi_in_testaSINGLY(listaTS, 123);
listaTS=aggiungi_in_testaSINGLY(listaTS, 6304);
listaTS=aggiungi_in_testaSINGLY(listaTS, 345);
listaTS=aggiungi_in_testaSINGLY(listaTS, 3962);
listaTS=aggiungi_in_testaSINGLY(listaTS, 567);
listaTS=aggiungi_in_testaSINGLY(listaTS, 8);
listaTS=aggiungi_in_testaSINGLY(listaTS, 99);
listaTS=aggiungi_in_testaSINGLY(listaTS, 6727);
listaTS=aggiungi_in_testaSINGLY(listaTS, 987);
listaTS=aggiungi_in_testaSINGLY(listaTS, 1234);
listaTS=aggiungi_in_testaSINGLY(listaTS, 234);
listaTS=aggiungi_in_testaSINGLY(listaTS, 2947);
listaTS=aggiungi_in_testaSINGLY(listaTS, 345);
listaTS=aggiungi_in_testaSINGLY(listaTS, 67);
listaTS=aggiungi_in_testaSINGLY(listaTS, 6);
listaTS=aggiungi_in_testaSINGLY(listaTS, 15);
listaTS=aggiungi_in_testaSINGLY(listaTS, 4444);
listaTS=aggiungi_in_testaSINGLY(listaTS, 37);
listaTS=aggiungi_in_testaSINGLY(listaTS, 9376);
listaTS=aggiungi_in_testaSINGLY(listaTS, 44);
listaTS=aggiungi_in_testaSINGLY(listaTS, 9726);
listaTS=aggiungi_in_testaSINGLY(listaTS, 66);
listaTS=aggiungi_in_testaSINGLY(listaTS, 5169);
listaTS=aggiungi_in_testaSINGLY(listaTS, 88);
listaTS=aggiungi_in_testaSINGLY(listaTS, 11573);
listaTS=aggiungi_in_testaSINGLY(listaTS, 73);
listaTS=aggiungi_in_testaSINGLY(listaTS, 896);
listaTS=aggiungi_in_testaSINGLY(listaTS, 69);
listaTS=aggiungi_in_testaSINGLY(listaTS, 627);
listaTS=aggiungi_in_testaSINGLY(listaTS, 15839);
listaTS=aggiungi_in_testaSINGLY(listaTS, 482);
listaTS=aggiungi_in_testaSINGLY(listaTS, 7825);
listaTS=aggiungi_in_testaSINGLY(listaTS, 555);
listaTS=aggiungi_in_testaSINGLY(listaTS, 1000);
listaTS=aggiungi_in_testaSINGLY(listaTS, 843);
listaTS=aggiungi_in_testaSINGLY(listaTS, 2);
listaTS=aggiungi_in_testaSINGLY(listaTS, 7311);
listaTS=aggiungi_in_testaSINGLY(listaTS, 0);
listaTS=aggiungi_in_testaSINGLY(listaTS, -7);
listaTS=aggiungi_in_testaSINGLY(listaTS, 257);
listaTS=aggiungi_in_testaSINGLY(listaTS, 44);
listaTS=aggiungi_in_testaSINGLY(listaTS, 3411);
listaTS=aggiungi_in_testaSINGLY(listaTS, 14);
listaTS=aggiungi_in_testaSINGLY(listaTS, 2384);
listaTS=aggiungi_in_testaSINGLY(listaTS, 772);
listaTS=aggiungi_in_testaSINGLY(listaTS, -9);
listaTS=aggiungi_in_testaSINGLY(listaTS, 8833);
listaTS=aggiungi_in_testaSINGLY(listaTS, 13);
listaTS=aggiungi_in_testaSINGLY(listaTS, 5240);
listaTS=aggiungi_in_testaSINGLY(listaTS, 49);
listaTS=aggiungi_in_testaSINGLY(listaTS, 113);
listaTS=aggiungi_in_testaSINGLY(listaTS, 6294);
listaTS=aggiungi_in_testaSINGLY(listaTS, 335);
listaTS=aggiungi_in_testaSINGLY(listaTS, 3952);
listaTS=aggiungi_in_testaSINGLY(listaTS, 557);
listaTS=aggiungi_in_testaSINGLY(listaTS, -2);
listaTS=aggiungi_in_testaSINGLY(listaTS, 89);
listaTS=aggiungi_in_testaSINGLY(listaTS, 6717);
listaTS=aggiungi_in_testaSINGLY(listaTS, 977);
listaTS=aggiungi_in_testaSINGLY(listaTS, 1224);
listaTS=aggiungi_in_testaSINGLY(listaTS, 224);
listaTS=aggiungi_in_testaSINGLY(listaTS, 2937);
listaTS=aggiungi_in_testaSINGLY(listaTS, 335);
listaTS=aggiungi_in_testaSINGLY(listaTS, 57);
listaTS=aggiungi_in_testaSINGLY(listaTS, -4);
listaTS=aggiungi_in_testaSINGLY(listaTS, 5);
listaTS=aggiungi_in_testaSINGLY(listaTS, 4434);
listaTS=aggiungi_in_testaSINGLY(listaTS, 27);
listaTS=aggiungi_in_testaSINGLY(listaTS, 9366);
listaTS=aggiungi_in_testaSINGLY(listaTS, 34);
listaTS=aggiungi_in_testaSINGLY(listaTS, 9716);
listaTS=aggiungi_in_testaSINGLY(listaTS, 56);
listaTS=aggiungi_in_testaSINGLY(listaTS, 5159);
listaTS=aggiungi_in_testaSINGLY(listaTS, 78);
listaTS=aggiungi_in_testaSINGLY(listaTS, 11563);
listaTS=aggiungi_in_testaSINGLY(listaTS, 63);
listaTS=aggiungi_in_testaSINGLY(listaTS, 886);
listaTS=aggiungi_in_testaSINGLY(listaTS, 59);
listaTS=aggiungi_in_testaSINGLY(listaTS, 617);
listaTS=aggiungi_in_testaSINGLY(listaTS, 15829);
listaTS=aggiungi_in_testaSINGLY(listaTS, 472);
listaTS=aggiungi_in_testaSINGLY(listaTS, 7815);
listaTS=aggiungi_in_testaSINGLY(listaTS, 545);
listaTS=aggiungi_in_testaSINGLY(listaTS, 990);
listaTS=aggiungi_in_testaSINGLY(listaTS, 833);
listaTS=aggiungi_in_testaSINGLY(listaTS, -8);

// FINE INSERIMENTO IN TESTA

	printf("lista originaria disordinata:\n");
    stampa_lista(listaTS);
	printf("\n");

	listaTS_COP=list_copy_recu(listaTS);

	listaTS_ORD=bubble_sort_lista(listaTS);
	printf("lista ordinata:\n");
    stampa_lista(listaTS_ORD);
	printf("\n");

	listaTS_ORD_COP=list_copy_recu(listaTS_ORD);

	listaTS_INV=list_reverse_recu(listaTS_ORD);
	printf("lista ordinata invertita:\n");
    stampa_lista(listaTS_INV);
	printf("\n\n");

	listaTS_INV_COP=list_copy_recu(listaTS_INV);

// INIZIO ORDINAMENTO BUBBLE SORT SU LISTA SINGLY LINKED DISORDINATA
	begin = clock();
	listaRIS1=bubble_sort_lista(listaTS_COP);
	for (cont=1;cont<2000;cont++)
		{
			printf("%d ", cont-cont);
		}
	printf("\n\n");
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("tempo di esecuzione Clock() (lista disordinata -> ORDINAMENTO CON BUBBLE SORT): %f seconds\n", time_spent);
	printf("\n");
// FINE ORDINAMENTO BUBBLE SORT SU LISTA SINGLY LINKED DISORDINATA
	printf("dopo ordinamento: ");
    stampa_lista(listaRIS1);
	printf("\n\n");

// INIZIO ORDINAMENTO BUBBLE SORT SU LISTA SINGLY LINKED GIA' ORDINATA
	begin = clock();
	listaRIS2=bubble_sort_lista(listaTS_ORD_COP);
	for (cont=1;cont<2000;cont++)
		{
			printf("%d ", cont-cont);
		}
	printf("\n\n");
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("tempo di esecuzione Clock() (lista già ordinata -> ORDINAMENTO CON BUBBLE SORT): %f seconds\n", time_spent);
	printf("\n");
// FINE ORDINAMENTO BUBBLE SORT SU LISTA SINGLY LINKED GIA' ORDINATA
	printf("dopo ordinamento: ");
    stampa_lista(listaRIS2);
	printf("\n\n");

// INIZIO ORDINAMENTO BUBBLE SORT SU LISTA SINGLY LINKED INVERTITA - ordinata in senso inverso
	begin = clock();
	listaRIS3=bubble_sort_lista(listaTS_INV_COP);
	for (cont=1;cont<2000;cont++)
		{
			printf("%d ", cont-cont);
		}
	printf("\n\n");
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("tempo di esecuzione Clock() (lista invertita -> ORDINAMENTO CON BUBBLE SORT): %f seconds\n", time_spent);
	printf("\n");
// FINE ORDINAMENTO BUBBLE SORT SU LISTA SINGLY LINKED INVERTITA - ordinata in senso inverso
	printf("dopo ordinamento: ");
    stampa_lista(listaRIS3);
	printf("\n\n");
}
