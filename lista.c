#include "lista.h"

struct list_{
	int n;
	struct aresta_ * prim;
};

struct aresta_{
	int orig;
	int dest;
	struct aresta_ * prox;
};

Lista criar(){
	Lista l = malloc(sizeof(struct list_));
	l->prim = NULL;
	l->n = 0;

	return l;
}
void add(Lista l, int orig, int dest){
	struct aresta_ * aresta = malloc(sizeof(struct aresta_));
	
	aresta->orig = orig;
	aresta->dest = dest;

	aresta->prox = l->prim;
	l->prim = aresta;
	l->n++;
}

int remove(Lista l, int * orig, int * dest){
	if(l->n <= 0) return 0;
	struct aresta_ * ar = l->prim;
	l->prim = ar->prox;
	
	if(orig != NULL){
	*orig = ar->orig;
	*dest = ar->dest;
	}
	
	free(ar);
	l->n--;
	return 1;
}

void destroy(Lista l){
	while(l->n > 0) remove(l, NULL, NULL);
	free(l);
}