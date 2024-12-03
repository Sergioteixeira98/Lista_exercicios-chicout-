// (Ponto médio)  Escreva uma função que receba uma lista encadeada e devolva o endereço de uma célula que esteja 
// o mais próximo possível do meio da lista. Faça isso sem contar explicitamente o número de células da lista.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No *prox;
} No;

No *encontrarPontoMedio(No *inicio) {
    No *ptrRapido = inicio;
    No *ptrLento = inicio;
    
    while (ptrRapido != NULL && ptrRapido->prox != NULL) {
        ptrRapido = ptrRapido->prox->prox;
        ptrLento = ptrLento->prox;
    }
    
    return ptrLento;
}

No *criarNo(int val) {
    No *novo = (No *)malloc(sizeof(No));
    novo->val = val;
    novo->prox = NULL;
    return novo;
}

int main() {
    No *lst = criarNo(1);
    lst->prox = criarNo(2);
    lst->prox->prox = criarNo(3);
    lst->prox->prox->prox = criarNo(4);
    lst->prox->prox->prox->prox = criarNo(5);

    No *meio = encontrarPontoMedio(lst);
    
    if (meio != NULL) {
        printf("O valor do ponto médio é: %d\n", meio->val);
    }

    No *atual;
    while (lst != NULL) {
        atual = lst;
        lst = lst->prox;
        free(atual);
    }

    return 0;
}