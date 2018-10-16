#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

struct grafo {
    int qtd_vertices;
    int qtd_arestas;
    int* grau;          // Vetor para guardar o grau de cada vertice
    int** aresta;       // Vetor para guardar as arestas
};


/// FUNÇÕES BÁSICAS DE UM GRAFO

Grafo* cria_grafo (int vertices) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));

    if (g == NULL) {
        // Grafo não foi corretamente alocado
        return NULL;
    }

    g->qtd_vertices = vertices;
    g->qtd_arestas = 0;             // Grafo inicialmente vazio

    g->grau = (int*)calloc(vertices,sizeof(int));

    if (g->grau == NULL) {
        // Vetor de grau não foi corretamente alocado
        free(g);
        return NULL;
    }

    g->aresta = (int**)calloc(vertices,sizeof(int*));

    if (g->aresta == NULL) {
        // Vetor de arestas não foi corretamente alocado
        free(g->grau);
        free(g);
        return NULL;
    }

    int i; // Variável que vai alocar cada posiçao do vetor de arestas
    int j; // Variavel que vai auxiliar a desalocar caso haja algum problema

    for (i=0; i< vertices; i++) {
        g->aresta[i] = (int*)calloc(vertices, sizeof(int));

        if (g->aresta[i] == NULL) {
            // Alguma aresta não foi alocada corretamente
            for(j=0; j< i; j++) {
                free(g->aresta[j]); // Libera cada aresta que foi alocada antes da aresta que deu problema
            }

            free(g->aresta);
            free(g->grau);
            free(g);
            return NULL;
        }
    }

    return g;

}

int insere_aresta(Grafo* g, int v1, int v2) {
    if (g == NULL || v1 < 0 || v2 < 0) return -1; // Grafo não existe ou vértices inválidos (negativos)

    if (g->aresta[v1][v2] == 1 && g->aresta[v2][v1] == 1) return 0; // Aresta já existe

    g->aresta[v1][v2] = 1;
    g->aresta[v2][v1] = 1;

    g->qtd_arestas++;   // Incrementa a quantidade de arestas do grafo
    g->grau[v1]++;      // Incrementa o grau do vertice v1
    g->grau[v2]++;      // Incrementa o grau do vertice v2

    return 1;

}

int remove_aresta(Grafo* g, int v1, int v2) {
    if (g == NULL || v1 < 0 || v2 < 0) return -1; // Grafo não existe ou vértices invalidos (negativos)

    if (g->aresta[v1][v2] == 0 && g->aresta[v2][v1] == 0) return 0; // Aresta nao existe

    g->aresta[v1][v2] = 0;
    g->aresta[v2][v1] = 0;

    g->qtd_arestas--;   // Decrementa a quantidade de arestas do grafo
    g->grau[v1]--;      // Decrementa o grau do vertice v1
    g->grau[v2]--;      // Decrementa o grau do vertice v2

    return 1;
}

int verifica_adjacencia (Grafo* g, int v1, int v2) {
    if (g == NULL || v1 < 0 || v2 < 0) return -1; // Grafo não existe ou vértices inválidos (negativos)

    if (g->aresta[v1][v2] == 1 && g->aresta[v2][v1] == 1) return 1;
    else return 0;
}

void exibe_grafo(Grafo* g) {
    if (g == NULL || g->qtd_arestas == 0) {
        // Grafo não existe ou está vazio
        printf("Grafo não existe ou está vazio!\n");
        return;
    }

    int i, j;

    for (i=0;i< g->qtd_vertices; i++) {
        for (j=0; j< g->qtd_vertices; j++) {
            if (g->aresta[i][j] == 1) {
                // Vértices são adjacentes
                printf(" %d -> %d \n", i, j);
            }
        }
    }
}

void libera_grafo(Grafo** g) {
    if (g == NULL) return; // Grafo não existe

    int i;

    for (i=0;i< (*g)->qtd_vertices;i++) {
        // Libera cada posição do vetor de arestas
        free((*g)->aresta[i]);
    }

    free((*g)->aresta);
    free((*g)->grau);
    free(*g);

    *g = NULL;
}

/// FUNÇÕES ESPECÍFICAS DO TRABALHO
int numero_vertices(Grafo* g) {
    return g->qtd_vertices;
}

int numero_arestas (Grafo* g) {
    return g->qtd_arestas;
}

int busca_largura (Grafo* g, int v1) {
    if (g == NULL) return -1; // Grafo não existe

    int atual, i;
    int* visitados;
    int vertices;
    fila* fi;

    vertices = g->qtd_vertices;

    visitados = (int*)calloc(vertices, sizeof(int));

    if (visitados == NULL) {
        // Problema para alocar o vetor de visitados
        return -1;
    }

    fi = cria_fila();

    if (fi == NULL) {
        // Problema para alocar a fila
        free(visitados);
        return -1;
    }

    // Trata o vértice inicial (v1 == 1)
    visitados[v1] = 1;
    insere_fila(fi, v1);

    while(!fila_vazia(fi)) {
        // Enquanto a fila não for vazia
        atual = remove_fila_v2(fi);

        for(i=0;i< vertices; i++) {
            if (visitados[i] == 0 && verifica_adjacencia(g, atual, i)) {
                // Se o vertice "i" ainda não foi visitado e ele é adjacente ao vertice "atual"
                insere_fila(fi, i);
                visitados[i] = 1;

            }
        }
    }

    for (i=0; i< vertices; i++) {
        printf("visitados[%d] = %d\n", i, visitados[i]);
    }

    return 1;

}



