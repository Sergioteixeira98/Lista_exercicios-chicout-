// Escreva uma função que obtém o espelho de uma árvore, ou seja, troca a subárvore direita pela subárvore esquerda de todos os nós da árvore

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo* esquerda;
    struct Nodo* direita;
};

struct Nodo* criarNodo(int valor) {
    struct Nodo* novo = (struct Nodo*)malloc(sizeof(struct Nodo));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void espelharArvore(struct Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }

    struct Nodo* temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;

    espelharArvore(raiz->esquerda);
    espelharArvore(raiz->direita);
}

void imprimirEmOrdem(struct Nodo* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    struct Nodo* raiz = criarNodo(1);
    raiz->esquerda = criarNodo(2);
    raiz->direita = criarNodo(3);
    raiz->esquerda->esquerda = criarNodo(4);
    raiz->esquerda->direita = criarNodo(5);
    raiz->direita->esquerda = criarNodo(6);
    raiz->direita->direita = criarNodo(7);

    printf("Árvore original em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    espelharArvore(raiz);

    printf("Árvore espelhada em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    return 0;
}
