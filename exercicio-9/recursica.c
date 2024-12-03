#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No *prox;
} No;

No *encontrarMinimoRecursivo(No *inicio, No *min) {
    if (inicio == NULL) {
        return min;
    }
    if (min == NULL || inicio->val < min->val) {
        min = inicio;
    }
    return encontrarMinimoRecursivo(inicio->prox, min);
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

    No *min = encontrarMinimoRecursivo(inicio, NULL);
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