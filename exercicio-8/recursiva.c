#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val;
    struct Nodo *prox;
} Nodo;

int buscaRecursiva(Nodo *inicio, int chave) {
    if (inicio == NULL) {
        return 0;
    }
    if (inicio->val == chave) {
        return 1;
    }
    return buscaRecursiva(inicio->prox, chave);
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

    if (buscaRecursiva(inicio, 4)) {
        printf("Elemento encontrado\n");
    } else {
        printf("Elemento não encontrado\n");
    }

    Nodo *atual = inicio;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}