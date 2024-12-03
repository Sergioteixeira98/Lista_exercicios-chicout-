#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No *prox;
} No;

int listasIguaisRecursivo(No *l1, No *l2) {
    if (l1 == NULL && l2 == NULL) {
        return 1;
    }
    if (l1 == NULL || l2 == NULL || l1->val != l2->val) {
        return 0;
    }
    return listasIguaisRecursivo(l1->prox, l2->prox);
}

No *criarNo(int val) {
    No *novo = (No *)malloc(sizeof(No));
    novo->val = val;
    novo->prox = NULL;
    return novo;
}

int main() {
    No *l1 = criarNo(1);
    l1->prox = criarNo(2);
    l1->prox->prox = criarNo(3);

    No *l2 = criarNo(1);
    l2->prox = criarNo(2);
    l2->prox->prox = criarNo(3);

    if (listasIguaisRecursivo(l1, l2)) {
        printf("As listas são iguais\n");
    } else {
        printf("As listas são diferentes\n");
    }

    No *atual;
    while (l1 != NULL) {
        atual = l1;
        l1 = l1->prox;
        free(atual);
    }
    while (l2 != NULL) {
        atual = l2;
        l2 = l2->prox;
        free(atual);
    }

    return 0;
}
