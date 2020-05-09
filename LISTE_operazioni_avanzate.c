#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TInfo;

// struttura/tipo di Singly Linked List
typedef struct SNode {
    TInfo info;
    struct SNode* link;
} TNode;

typedef TNode* TList;

bool greater(TInfo a, TInfo b)  /* a segue (è più grande di) b */
{
return a > b;
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

// STAMPA LISTA
void stampa_lista(TList l)
{
    while(l != NULL) {
        printf("%d  ", l->info);
        l = l->link;
    }
    printf("\n");
}

// TROVA IL MINIMO ITERATIVAMENTE
TList list_min(TList list)
{
  TList curr, min;
  curr = list;
  min = curr;
  while (curr!=NULL){
    if (greater(min->info, curr->info)) {
      min = curr;
    }
    curr = curr->link;
  }
  return min;
}

// TROVA IL MINIMO RICORSIVAMENTE
TList list_min_recu(TList list) {
  if(list==NULL)
    return NULL;
  else
  {
    TList min_coda = list_min_recu(list->link);
    if((min_coda!=NULL) && greater(list->info, min_coda->info))
      return min_coda;
    else
      return list; 
  }
}

// CONTA I NODI ITERATIVAMENTE
int list_count_nodes(TList list)
{
  TList curr;
  int n = 0;
  curr = list;
  while (curr!=NULL){
    n = n + 1;
    curr = curr->link;
  }
  return n;
}

// CONTA I NODI RICORSIVAMENTE
int list_count_nodes_recu(TList list) {
  if(list==NULL)
    return 0;
  else
  {
    int num_coda = list_count_nodes_recu(list->link);
    return num_coda+1;
  }
}

// SOMMA I VALORI DEI NODI ITERATIVAMENTE
int list_sum_nodes(TList list)
{
  TList curr;
  int sum = 0;
  curr = list;
  while (curr!=NULL){
    sum = sum + curr->info;
    curr = curr->link;
  }
  return sum;
}

// SOMMA I VALORI DEI NODI RICORSIVAMENTE
int list_sum_nodes_recu(TList list) {
  if(list==NULL)
    return 0;
  else
  {
    int sum_coda = list_sum_nodes_recu(list->link);
    return sum_coda+list->info;
  }
}

// INVERTI LA LISTA (ALGORITMO ITERATIVO)
TList list_reverse(TList list)
{
  TList curr, prec, succ;
  curr = list;
  prec = NULL ;
  while (curr!=NULL){
    succ=curr->link;
    curr->link=prec;
    prec=curr;
    curr=succ;
  }
  return prec;
}

// INVERTI LA LISTA (ALGORITMO RICORSIVO)
TList list_reverse_recu(TList list) {
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

// COPIA LA LISTA ITERATIVAMENTE
TList list_copy(TList list)
{
  TList curr, l2, succ;
  curr = list;
  succ = NULL;
  while (curr!=NULL){
    TList tmp = (TNode *) malloc(sizeof(TNode));
    tmp->info = curr->info;
    tmp->link = NULL;
    if (succ == NULL){
       l2 = tmp;
       succ = tmp;
    }
    else {
       succ->link = tmp;
       succ = tmp; 
    }   
    curr=curr->link;
  }
  return l2;
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

// FUSIONE RICORSIVA TRA LISTE
TList list_merge_recursive (TList l1 , TList l2) {
   TList lf=NULL;
  if (l1==NULL) {
    lf = list_copy_recu(l2);
    return lf;
  }
  if (l2==NULL) {
    lf = list_copy_recu(l1);
    return lf;
  }
  if(greater(l2->info, l1->info))
  {
     lf = list_merge_recursive(l1->link, l2);
	 TList tmp = (TNode *) malloc (sizeof(TNode));
     if(tmp==NULL) {
       printf("Errore di allocazione della memoria\n");
       exit(1);
     }
     tmp->info = l1->info;
     tmp->link = lf;
     return tmp;
   }
   else {
     lf = list_merge_recursive(l1, l2->link);
     TList tmp = (TNode *) malloc (sizeof(TNode));
     if(tmp==NULL) {
       printf("Errore di allocazione della memoria\n");
       exit(1);
     }   
	 tmp->info = l2->info;
     tmp->link = lf;
     return tmp;
   }
}

int main()
{
	TList listaTS = NULL, listaT = NULL, copyTS = NULL, copyT = NULL, copy = NULL;

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

listaT=aggiungi_in_testaSINGLY(listaT, 2);
listaT=aggiungi_in_testaSINGLY(listaT, 30);
listaT=aggiungi_in_testaSINGLY(listaT, 529);
listaT=aggiungi_in_testaSINGLY(listaT, 142);
listaT=aggiungi_in_testaSINGLY(listaT, 67);

	printf("\n");
	printf("lista TS\n");
    stampa_lista(listaTS);

	printf("lista T\n");
    stampa_lista(listaT);
	printf("\n\n");

printf("minimo TS (proc. iterativa): %d\n",list_min(listaTS)->info);
printf("minimo T (proc. ricorsiva): %d\n",list_min_recu(listaT)->info);
	printf("\n");
printf("n. nodi TS (proc. iterativa): %d\n",list_count_nodes(listaTS));
printf("n. nodi T (proc. ricorsiva): %d\n",list_count_nodes_recu(listaT));
	printf("\n");
printf("somma nodi TS (proc. iterativa): %d\n",list_sum_nodes(listaTS));
printf("somma nodi T (proc. ricorsiva): %d\n",list_sum_nodes_recu(listaT));
	printf("\n");
listaTS=list_reverse(listaTS);
	printf("lista TS invertita iterativamente\n");
    stampa_lista(listaTS);

listaT=list_reverse_recu(listaT);
	printf("lista T invertita ricorsivamente\n");
    stampa_lista(listaT);
	printf("\n");
copyTS=list_copy(listaTS);
	printf("lista copyTS copiata iterativamente da TS\n");
    stampa_lista(copyTS);

copyT=list_copy_recu(listaT);
	printf("lista copyT copiata ricorsivamente da T\n");
    stampa_lista(copyT);
	printf("\n");

	printf("fondo copyTS e copyT in un'unica lista ... il risultato del merge è la lista copy:\n");
copy=list_merge_recursive (copyTS , copyT);
    stampa_lista(copy);

    return 0;
}
