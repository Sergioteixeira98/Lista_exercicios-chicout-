// Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça versões recursiva e iterativa.

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val;
    struct Nodo *prox;
} Nodo;

int buscaIterativa(Nodo *inicio, int chave) {
    Nodo *nodoAtual = inicio;
    while (nodoAtual != NULL) {
        if (nodoAtual->val == chave) {
            return 1;
        }
        nodoAtual = nodoAtual->prox;
    }
    return 0;
}

Nodo *novoNodo(int val) {
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    n->val = val;
    n->prox = NULL;
    return n;
}

int main() {
    Nodo *inicio = novoNodo(1);
    inicio->prox = novoNodo(3);
    inicio->prox->prox = novoNodo(5);

    if (buscaIterativa(inicio, 3)) {
        printf("Elemento encontrado\n");
    } else {
        printf("Elemento não encontrado\n");
    }

    Nodo *nodoAtual = inicio;
    while (nodoAtual != NULL) {
        Nodo *temp = nodoAtual;
        nodoAtual = nodoAtual->prox;
        free(temp);
    }

    return 0;
}