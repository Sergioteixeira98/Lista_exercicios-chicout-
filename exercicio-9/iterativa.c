// Escreva uma função que encontre uma célula com conteúdo mínimo. Faça duas versões: uma iterativa e uma recursiva.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No *prox;
} No;

No *encontrarMinimoIterativo(No *inicio) {
    if (inicio == NULL) {
        return NULL;
    }
    No *atual = inicio;
    No *min = inicio;
    while (atual != NULL) {
        if (atual->val < min->val) {
            min = atual;
        }
        atual = atual->prox;
    }
    return min;
}

No *criarNo(int val) {
    No *novo = (No *)malloc(sizeof(No));
    novo->val = val;
    novo->prox = NULL;
    return novo;
}

int main() {
    No *inicio = criarNo(7);
    inicio->prox = criarNo(3);
    inicio->prox->prox = criarNo(5);

    No *min = encontrarMinimoIterativo(inicio);
    if (min != NULL) {
        printf("O valor mínimo é: %d\n", min->val);
    }

    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}