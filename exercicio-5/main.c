// Usando listas dinâmicas, crie um programa que guarde strings. Re-implemente todas as funcionalidades para que seja 
// possível usar as funções básicas de inserção, remoção, busca e detecção de fim de lista;
// a. Implemente também a função que retorna o tamanho da lista (quantidade de elementos), e a perda de memória 
// (total da lista - quantidade de itens vazios)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado[100];
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void initLista(Lista *lst) {
    lst->inicio = NULL;
    lst->tam = 0;
}

void addLista(Lista *lst, const char *valor) {
    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->dado, valor);
    novo->prox = lst->inicio;
    lst->inicio = novo;
    lst->tam++;
}

void rmLista(Lista *lst, const char *valor) {
    No *ant = NULL, *atual = lst->inicio;
    while (atual != NULL && strcmp(atual->dado, valor) != 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (ant == NULL) {
            lst->inicio = atual->prox;
        } else {
            ant->prox = atual->prox;
        }
        free(atual);
        lst->tam--;
    }
}

No *buscarNaLista(Lista *lst, const char *valor) {
    No *atual = lst->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dado, valor) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

int tamLista(Lista *lst) {
    return lst->tam;
}

int memPerdida(Lista *lst) {
    int nodos = 0;
    No *atual = lst->inicio;
    while (atual != NULL) {
        nodos++;
        atual = atual->prox;
    }
    return nodos - lst->tam;
}

void liberar(Lista *lst) {
    No *atual = lst->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lst->inicio = NULL;
    lst->tam = 0;
}

void printLista(Lista *lst) {
    No *atual = lst->inicio;
    while (atual != NULL) {
        printf("%s\n", atual->dado);
        atual = atual->prox;
    }
}

int main() {
    Lista lst;
    initLista(&lst);

    addLista(&lst, "primeira");
    addLista(&lst, "segunda");
    addLista(&lst, "terceira");

    printLista(&lst);

    printf("Tamanho: %d\n", tamLista(&lst));
    printf("Perda de memoria: %d\n", memPerdida(&lst));

    rmLista(&lst, "segunda");
    printLista(&lst);

    liberar(&lst);
    return 0;
}
