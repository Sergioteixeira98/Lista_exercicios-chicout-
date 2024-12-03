// Escreva uma função que verifique se duas listas encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões: uma iterativa e uma recursiva.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No *prox;
} No;

int listasIguaisIterativo(No *l1, No *l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->val != l2->val) {
            return 0;
        }
        l1 = l1->prox;
        l2 = l2->prox;
    }
    return l1 == NULL && l2 == NULL;
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

    if (listasIguaisIterativo(l1, l2)) {
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