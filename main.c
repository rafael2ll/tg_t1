#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    int vertices=8;
    Grafo* g = cria_grafo(vertices);

    insere_aresta(g,2,1);
    insere_aresta(g,4,2);
    insere_aresta(g,5,3);
    insere_aresta(g,4,1);
    insere_aresta(g,7,6);

    exibe_grafo(g);

    printf("\n\n");

    busca_largura(g, 1);

    libera_grafo(&g);

    return 0;
}
