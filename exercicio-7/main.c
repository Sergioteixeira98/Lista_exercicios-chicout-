// Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val;
    struct Nodo *prox;
} Nodo;

int estaOrdenada(Nodo *inicio) {
    Nodo *atual = inicio;
    while (atual != NULL && atual->prox != NULL) {
        if (atual->val > atual->prox->val) {
            return 0;
        }
        atual = atual->prox;
    }
    return 1;
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

    if (estaOrdenada(inicio)) {
        printf("A lista está em ordem crescente\n");
    } else {
        printf("A lista não está em ordem crescente\n");
    }

    Nodo *atual = inicio;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
