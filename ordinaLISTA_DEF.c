#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int TInfo;

// struttura/tipo di Singly Linked List
typedef struct SNode {
    TInfo info;
    struct SNode* link;
} TNode;

typedef TNode* TList;

// struttura/tipo di Doubly Linked List
typedef struct SNodeDouble {
    TInfo info;
    struct SNodeDouble* next;
	struct SNodeDouble* prev;
} TNodeDouble;

typedef TNodeDouble* TListDouble;

// inserimento in CODA - su lista dinamica singly linked
TList aggiungi_in_coda(TList l, int nuovo_valore)
{
    TNode* nuovo_nodo = (TNode *)malloc(sizeof(TNode));
    nuovo_nodo->info = nuovo_valore;
    nuovo_nodo->link = NULL;

    if(l == NULL) {
        return nuovo_nodo;
    }
    TList tmp = l;
    while(tmp->link != NULL) {
        tmp = tmp->link;
    }
    // il prossimo e' NULL: inserisco il nuovo_nodo
    tmp->link = nuovo_nodo;

    // restituisco la lista originale
    return l;
}

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

// inserimento in TESTA - su lista dinamica doubly linked
TListDouble aggiungi_in_testa(TListDouble l, int nuovo_valore)
{
    //printf("sono qui - inizio inserimento in testa\n\n");
	TNodeDouble* nuovo_nodoD = (TNodeDouble *)malloc(sizeof(TNodeDouble));
    nuovo_nodoD->info = nuovo_valore;
	nuovo_nodoD->next=NULL;
	nuovo_nodoD->prev=NULL;
	if(l == NULL) {
		l = nuovo_nodoD;
		return l;
	}
	l->prev=nuovo_nodoD;
    nuovo_nodoD->next = l;
	l=nuovo_nodoD;

    // restituisco la lista originaria con nuovo nodo in testa
	//printf("sono qui - fine inserimento in testa\n\n");
    return l;
}

void stampa_lista(TList l)
{
    while(l != NULL) {
        printf("%d  ", l->info);
        l = l->link;
    }
    printf("\n");
}

void stampa_listaDoppia(TListDouble l)
{
    while(l != NULL) {
        printf("%d  ", l->info);
        l = l->next;
    }
    printf("\n");
}

// ORDINAMENTO LISTA CON BUBBLE SORT
void bubble_sort_lista(TList* lista)
{
    int temp;
    int modified = 1;
    TNode* l1 = NULL;
    TNode* l2 = NULL;

    while(modified == 1) {
        modified = 0;
        for(l1 = *lista; l1->link != NULL; l1 = l1->link) {
            for(l2 = l1->link; l2 != NULL; l2 = l2->link) {
                if(l1->info > l2->info) {
                    temp = l1->info;
                    l1->info = l2->info;
                    l2->info = temp;
                    modified = 1;
                }
            }
        }
    }
}

// SWAP TRA NODI IN LISTA A DOPPIO VERSO
void swap(TListDouble* list, TNodeDouble* node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

// ORDINAMENTO LISTA CON COKTAIL SHAKER SORT
void shaker_sort_lista(TListDouble* list)
{
	int modified = 1;
	TNodeDouble* temp = NULL;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (modified != 0)
	{
		modified = 0;
		while (temp->next != NULL)
		{
			if (temp->next->info < temp->info)
			{
				swap(list, temp);
				modified = 1;
			}
			else
				temp = temp->next;
		}
		if (modified == 0)
			break;
		modified = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->info > temp->info)
			{
				swap(list, temp->prev);
				modified = 1;
			}
			else
				temp = temp->prev;
		}
	}
}

int main()
{
	// USING CLOCK()
	double time_spent;
	clock_t begin, end;
	
	TList listaC = NULL, listaTS = NULL;
	TListDouble listaT = NULL;

	printf("\n");

	// INIZIO OPERAZIONI INSERIMENTO IN CODA + ORDINAMENTO CON BUBBLE SORT SU LISTA SINGLY LINKED
	
	begin = clock();

listaC=aggiungi_in_coda(listaC, 7321);
listaC=aggiungi_in_coda(listaC, 10);
listaC=aggiungi_in_coda(listaC, 3);
listaC=aggiungi_in_coda(listaC, 267);
listaC=aggiungi_in_coda(listaC, 54);
listaC=aggiungi_in_coda(listaC, 3421);
listaC=aggiungi_in_coda(listaC, 24);
listaC=aggiungi_in_coda(listaC, 2394);
listaC=aggiungi_in_coda(listaC, 782);
listaC=aggiungi_in_coda(listaC, 1);
listaC=aggiungi_in_coda(listaC, 8843);
listaC=aggiungi_in_coda(listaC, 23);
listaC=aggiungi_in_coda(listaC, 5250);
listaC=aggiungi_in_coda(listaC, 59);
listaC=aggiungi_in_coda(listaC, 123);
listaC=aggiungi_in_coda(listaC, 6304);
listaC=aggiungi_in_coda(listaC, 345);
listaC=aggiungi_in_coda(listaC, 3962);
listaC=aggiungi_in_coda(listaC, 567);
listaC=aggiungi_in_coda(listaC, 8);
listaC=aggiungi_in_coda(listaC, 99);
listaC=aggiungi_in_coda(listaC, 6727);
listaC=aggiungi_in_coda(listaC, 987);
listaC=aggiungi_in_coda(listaC, 1234);
listaC=aggiungi_in_coda(listaC, 234);
listaC=aggiungi_in_coda(listaC, 2947);
listaC=aggiungi_in_coda(listaC, 345);
listaC=aggiungi_in_coda(listaC, 67);
listaC=aggiungi_in_coda(listaC, 6);
listaC=aggiungi_in_coda(listaC, 15);
listaC=aggiungi_in_coda(listaC, 4444);
listaC=aggiungi_in_coda(listaC, 37);
listaC=aggiungi_in_coda(listaC, 9376);
listaC=aggiungi_in_coda(listaC, 44);
listaC=aggiungi_in_coda(listaC, 9726);
listaC=aggiungi_in_coda(listaC, 66);
listaC=aggiungi_in_coda(listaC, 5169);
listaC=aggiungi_in_coda(listaC, 88);
listaC=aggiungi_in_coda(listaC, 11573);
listaC=aggiungi_in_coda(listaC, 73);
listaC=aggiungi_in_coda(listaC, 896);
listaC=aggiungi_in_coda(listaC, 69);
listaC=aggiungi_in_coda(listaC, 627);
listaC=aggiungi_in_coda(listaC, 15839);
listaC=aggiungi_in_coda(listaC, 482);
listaC=aggiungi_in_coda(listaC, 7825);
listaC=aggiungi_in_coda(listaC, 555);
listaC=aggiungi_in_coda(listaC, 1000);
listaC=aggiungi_in_coda(listaC, 843);
listaC=aggiungi_in_coda(listaC, 2);
listaC=aggiungi_in_coda(listaC, 7311);
listaC=aggiungi_in_coda(listaC, 0);
listaC=aggiungi_in_coda(listaC, -7);
listaC=aggiungi_in_coda(listaC, 257);
listaC=aggiungi_in_coda(listaC, 44);
listaC=aggiungi_in_coda(listaC, 3411);
listaC=aggiungi_in_coda(listaC, 14);
listaC=aggiungi_in_coda(listaC, 2384);
listaC=aggiungi_in_coda(listaC, 772);
listaC=aggiungi_in_coda(listaC, -9);
listaC=aggiungi_in_coda(listaC, 8833);
listaC=aggiungi_in_coda(listaC, 13);
listaC=aggiungi_in_coda(listaC, 5240);
listaC=aggiungi_in_coda(listaC, 49);
listaC=aggiungi_in_coda(listaC, 113);
listaC=aggiungi_in_coda(listaC, 6294);
listaC=aggiungi_in_coda(listaC, 335);
listaC=aggiungi_in_coda(listaC, 3952);
listaC=aggiungi_in_coda(listaC, 557);
listaC=aggiungi_in_coda(listaC, -2);
listaC=aggiungi_in_coda(listaC, 89);
listaC=aggiungi_in_coda(listaC, 6717);
listaC=aggiungi_in_coda(listaC, 977);
listaC=aggiungi_in_coda(listaC, 1224);
listaC=aggiungi_in_coda(listaC, 224);
listaC=aggiungi_in_coda(listaC, 2937);
listaC=aggiungi_in_coda(listaC, 335);
listaC=aggiungi_in_coda(listaC, 57);
listaC=aggiungi_in_coda(listaC, -4);
listaC=aggiungi_in_coda(listaC, 5);
listaC=aggiungi_in_coda(listaC, 4434);
listaC=aggiungi_in_coda(listaC, 27);
listaC=aggiungi_in_coda(listaC, 9366);
listaC=aggiungi_in_coda(listaC, 34);
listaC=aggiungi_in_coda(listaC, 9716);
listaC=aggiungi_in_coda(listaC, 56);
listaC=aggiungi_in_coda(listaC, 5159);
listaC=aggiungi_in_coda(listaC, 78);
listaC=aggiungi_in_coda(listaC, 11563);
listaC=aggiungi_in_coda(listaC, 63);
listaC=aggiungi_in_coda(listaC, 886);
listaC=aggiungi_in_coda(listaC, 59);
listaC=aggiungi_in_coda(listaC, 617);
listaC=aggiungi_in_coda(listaC, 15829);
listaC=aggiungi_in_coda(listaC, 472);
listaC=aggiungi_in_coda(listaC, 7815);
listaC=aggiungi_in_coda(listaC, 545);
listaC=aggiungi_in_coda(listaC, 990);
listaC=aggiungi_in_coda(listaC, 833);
listaC=aggiungi_in_coda(listaC, -8);

    stampa_lista(listaC);
	printf("\n");

    bubble_sort_lista(&listaC);

    stampa_lista(listaC);
	printf("\n");

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("tempo di esecuzione Clock() (operazioni lista a singolo verso -> INSERIMENTO IN CODA + ORDINAMENTO CON BUBBLE SORT): %f seconds\n", time_spent);
	printf("\n\n");
	
	// FINE OPERAZIONI INSERIMENTO IN CODA + ORDINAMENTO CON BUBBLE SORT  SU LISTA SINGLY LINKED

	// INIZIO OPERAZIONI INSERIMENTO IN TESTA + ORDINAMENTO CON BUBBLE SORT SU LISTA SINGLY LINKED

	begin = clock();

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

    stampa_lista(listaTS);
	printf("\n");

    bubble_sort_lista(&listaTS);

    stampa_lista(listaTS);
	printf("\n");

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("tempo di esecuzione Clock() (operazioni lista a singolo verso -> INSERIMENTO IN TESTA + ORDINAMENTO CON BUBBLE SORT): %f seconds\n", time_spent);
	printf("\n\n");

	// FINE OPERAZIONI INSERIMENTO IN TESTA + ORDINAMENTO CON BUBBLE SORT  SU LISTA SINGLY LINKED


	// INIZIO OPERAZIONI INSERIMENTO IN TESTA + ORDINAMENTO CON SHAKER SORT SU LISTA DOUBLY LINKED

	begin = clock();

listaT=aggiungi_in_testa(listaT, 7321);
listaT=aggiungi_in_testa(listaT, 10);
listaT=aggiungi_in_testa(listaT, 3);
listaT=aggiungi_in_testa(listaT, 267);
listaT=aggiungi_in_testa(listaT, 54);
listaT=aggiungi_in_testa(listaT, 3421);
listaT=aggiungi_in_testa(listaT, 24);
listaT=aggiungi_in_testa(listaT, 2394);
listaT=aggiungi_in_testa(listaT, 782);
listaT=aggiungi_in_testa(listaT, 1);
listaT=aggiungi_in_testa(listaT, 8843);
listaT=aggiungi_in_testa(listaT, 23);
listaT=aggiungi_in_testa(listaT, 5250);
listaT=aggiungi_in_testa(listaT, 59);
listaT=aggiungi_in_testa(listaT, 123);
listaT=aggiungi_in_testa(listaT, 6304);
listaT=aggiungi_in_testa(listaT, 345);
listaT=aggiungi_in_testa(listaT, 3962);
listaT=aggiungi_in_testa(listaT, 567);
listaT=aggiungi_in_testa(listaT, 8);
listaT=aggiungi_in_testa(listaT, 99);
listaT=aggiungi_in_testa(listaT, 6727);
listaT=aggiungi_in_testa(listaT, 987);
listaT=aggiungi_in_testa(listaT, 1234);
listaT=aggiungi_in_testa(listaT, 234);
listaT=aggiungi_in_testa(listaT, 2947);
listaT=aggiungi_in_testa(listaT, 345);
listaT=aggiungi_in_testa(listaT, 67);
listaT=aggiungi_in_testa(listaT, 6);
listaT=aggiungi_in_testa(listaT, 15);
listaT=aggiungi_in_testa(listaT, 4444);
listaT=aggiungi_in_testa(listaT, 37);
listaT=aggiungi_in_testa(listaT, 9376);
listaT=aggiungi_in_testa(listaT, 44);
listaT=aggiungi_in_testa(listaT, 9726);
listaT=aggiungi_in_testa(listaT, 66);
listaT=aggiungi_in_testa(listaT, 5169);
listaT=aggiungi_in_testa(listaT, 88);
listaT=aggiungi_in_testa(listaT, 11573);
listaT=aggiungi_in_testa(listaT, 73);
listaT=aggiungi_in_testa(listaT, 896);
listaT=aggiungi_in_testa(listaT, 69);
listaT=aggiungi_in_testa(listaT, 627);
listaT=aggiungi_in_testa(listaT, 15839);
listaT=aggiungi_in_testa(listaT, 482);
listaT=aggiungi_in_testa(listaT, 7825);
listaT=aggiungi_in_testa(listaT, 555);
listaT=aggiungi_in_testa(listaT, 1000);
listaT=aggiungi_in_testa(listaT, 843);
listaT=aggiungi_in_testa(listaT, 2);
listaT=aggiungi_in_testa(listaT, 7311);
listaT=aggiungi_in_testa(listaT, 0);
listaT=aggiungi_in_testa(listaT, -7);
listaT=aggiungi_in_testa(listaT, 257);
listaT=aggiungi_in_testa(listaT, 44);
listaT=aggiungi_in_testa(listaT, 3411);
listaT=aggiungi_in_testa(listaT, 14);
listaT=aggiungi_in_testa(listaT, 2384);
listaT=aggiungi_in_testa(listaT, 772);
listaT=aggiungi_in_testa(listaT, -9);
listaT=aggiungi_in_testa(listaT, 8833);
listaT=aggiungi_in_testa(listaT, 13);
listaT=aggiungi_in_testa(listaT, 5240);
listaT=aggiungi_in_testa(listaT, 49);
listaT=aggiungi_in_testa(listaT, 113);
listaT=aggiungi_in_testa(listaT, 6294);
listaT=aggiungi_in_testa(listaT, 335);
listaT=aggiungi_in_testa(listaT, 3952);
listaT=aggiungi_in_testa(listaT, 557);
listaT=aggiungi_in_testa(listaT, -2);
listaT=aggiungi_in_testa(listaT, 89);
listaT=aggiungi_in_testa(listaT, 6717);
listaT=aggiungi_in_testa(listaT, 977);
listaT=aggiungi_in_testa(listaT, 1224);
listaT=aggiungi_in_testa(listaT, 224);
listaT=aggiungi_in_testa(listaT, 2937);
listaT=aggiungi_in_testa(listaT, 335);
listaT=aggiungi_in_testa(listaT, 57);
listaT=aggiungi_in_testa(listaT, -4);
listaT=aggiungi_in_testa(listaT, 5);
listaT=aggiungi_in_testa(listaT, 4434);
listaT=aggiungi_in_testa(listaT, 27);
listaT=aggiungi_in_testa(listaT, 9366);
listaT=aggiungi_in_testa(listaT, 34);
listaT=aggiungi_in_testa(listaT, 9716);
listaT=aggiungi_in_testa(listaT, 56);
listaT=aggiungi_in_testa(listaT, 5159);
listaT=aggiungi_in_testa(listaT, 78);
listaT=aggiungi_in_testa(listaT, 11563);
listaT=aggiungi_in_testa(listaT, 63);
listaT=aggiungi_in_testa(listaT, 886);
listaT=aggiungi_in_testa(listaT, 59);
listaT=aggiungi_in_testa(listaT, 617);
listaT=aggiungi_in_testa(listaT, 15829);
listaT=aggiungi_in_testa(listaT, 472);
listaT=aggiungi_in_testa(listaT, 7815);
listaT=aggiungi_in_testa(listaT, 545);
listaT=aggiungi_in_testa(listaT, 990);
listaT=aggiungi_in_testa(listaT, 833);
listaT=aggiungi_in_testa(listaT, -8);

    stampa_listaDoppia(listaT);
	printf("\n");

    shaker_sort_lista(&listaT);

    stampa_listaDoppia(listaT);
	printf("\n");

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("tempo di esecuzione Clock() (operazioni lista a doppio verso -> INSERIMENTO IN TESTA + ORDINAMENTO CON SHAKER SORT): %f seconds\n", time_spent);
	printf("\n\n");

	// FINE OPERAZIONI INSERIMENTO IN TESTA + ORDINAMENTO CON SHAKER SORT SU LISTA DOUBLY LINKED

    return 0;
}
