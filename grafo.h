#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct grafo Grafo;

/// FUNÇÕES PADRÕES DE UM GRAFO SIMPLES
Grafo* cria_grafo (int vertices);
int insere_aresta (Grafo* g, int v1, int v2);
int remove_aresta (Grafo* g, int v1, int v2);
int verifica_adjacencia (Grafo* g, int v1, int v2);
void exibe_grafo (Grafo* g);
void libera_grafo (Grafo** g);

/// FUNÇÕES ESPECIFICAS DO TRABALHO
int numero_vertices (Grafo* g);     // Função que retorna a quantidade de vértices do grafo
int numero_arestas (Grafo* g);      // Função que retorna a quantidade de arestas do grafo
int busca_largura (Grafo* g, int v1);
int eh_conexo (Grafo* g);           // Função que verifica se um grafo é conexo


#endif // GRAFO_H_INCLUDED
