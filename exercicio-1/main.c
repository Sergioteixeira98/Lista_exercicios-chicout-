// Dada uma lista sequencial ordenada estática L1, escreva métodos em C que:
// a. Verifique se L1 está ordenada ou não (a ordem pode ser crescente ou decrescente)
// b. Faça uma cópia da lista L1 em uma outra lista L2;
// c. Faça uma cópia da Lista L1 em L2, eliminando elementos repetidos;
// d. Inverta L1 colocando o resultado em L2;
// e. Inverta L1 colocando o resultado na própria L1;
// f. Intercale L1 com a lista L2, gerando a lista L3. considere que L1, L2 e L3 são ordenadas.
// g. Gere uma lista L2 onde cada registro contém dois campos de informação: elem contém um elemento de L1, 
// e count contém quantas vezes este elemento aparece em L1.
// h. Elimine de L1 todas as ocorrências de um elemento dado, L1 ordenada.
// i. Assumindo que os elementos da lista L1 são inteiros positivos, forneça os elementos que 
// aparecem o maior e o menor número de vezes (forneça os elementos e o número de vezes correspondente)

#include <stdio.h>
#include <string.h>

typedef struct {
    int elementos[50];
    int tamanho;
} ListaEstatica;

void verificarOrdenacaoLista(ListaEstatica lista) {
    int ehCrescente = 1, ehDecrescente = 1;
    for (int i = 0; i < lista.tamanho - 1; i++) {
        if (lista.elementos[i] > lista.elementos[i + 1]) ehCrescente = 0;
        if (lista.elementos[i] < lista.elementos[i + 1]) ehDecrescente = 0;
    }
    if (ehCrescente) printf("Crescente\n");
    else if (ehDecrescente) printf("Decrescente\n");
    else printf("Nao ordenada\n");
}

void copiarListaPara(ListaEstatica origem, ListaEstatica *destino) {
    destino->tamanho = origem.tamanho;
    for (int i = 0; i < origem.tamanho; i++) {
        destino->elementos[i] = origem.elementos[i];
    }
}

void copiarListaSemRepeticao(ListaEstatica origem, ListaEstatica *destino) {
    destino->tamanho = 0;
    for (int i = 0; i < origem.tamanho; i++) {
        int jaExiste = 0;
        for (int j = 0; j < destino->tamanho; j++) {
            if (destino->elementos[j] == origem.elementos[i]) jaExiste = 1;
        }
        if (!jaExiste) destino->elementos[destino->tamanho++] = origem.elementos[i];
    }
}

void inverterListaPara(ListaEstatica origem, ListaEstatica *destino) {
    destino->tamanho = origem.tamanho;
    for (int i = 0; i < origem.tamanho; i++) {
        destino->elementos[i] = origem.elementos[origem.tamanho - 1 - i];
    }
}

void inverterListaPropria(ListaEstatica *lista) {
    for (int i = 0; i < lista->tamanho / 2; i++) {
        int temp = lista->elementos[i];
        lista->elementos[i] = lista->elementos[lista->tamanho - 1 - i];
        lista->elementos[lista->tamanho - 1 - i] = temp;
    }
}

void intercalarListasOrdenadas(ListaEstatica lista1, ListaEstatica lista2, ListaEstatica *lista3) {
    int i = 0, j = 0, k = 0;
    while (i < lista1.tamanho && j < lista2.tamanho) {
        if (lista1.elementos[i] < lista2.elementos[j]) 
            lista3->elementos[k++] = lista1.elementos[i++];
        else 
            lista3->elementos[k++] = lista2.elementos[j++];
    }
    while (i < lista1.tamanho) lista3->elementos[k++] = lista1.elementos[i++];
    while (j < lista2.tamanho) lista3->elementos[k++] = lista2.elementos[j++];
    lista3->tamanho = k;
}

void contarElementosUnicos(ListaEstatica lista, ListaEstatica *resultado) {
    resultado->tamanho = 0;
    for (int i = 0; i < lista.tamanho; i++) {
        int posicao = -1;
        for (int j = 0; j < resultado->tamanho; j++) {
            if (resultado->elementos[j] == lista.elementos[i]) posicao = j;
        }
        if (posicao == -1) {
            resultado->elementos[resultado->tamanho++] = lista.elementos[i];
        }
    }
}

void removerElementoDaLista(ListaEstatica *lista, int valorRemover) {
    int novoTamanho = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] != valorRemover) {
            lista->elementos[novoTamanho++] = lista->elementos[i];
        }
    }
    lista->tamanho = novoTamanho;
}

void encontrarMaiorEMenorFrequencia(ListaEstatica lista) {
    int frequencias[50] = {0}, maiorFreq = 0, menorFreq = lista.tamanho + 1, elementoMaior, elementoMenor;
    for (int i = 0; i < lista.tamanho; i++) {
        int posicao = lista.elementos[i];
        frequencias[posicao]++;
    }
    for (int i = 0; i < 50; i++) {
        if (frequencias[i] > maiorFreq) {
            maiorFreq = frequencias[i];
            elementoMaior = i;
        }
        if (frequencias[i] < menorFreq && frequencias[i] > 0) {
            menorFreq = frequencias[i];
            elementoMenor = i;
        }
    }
    printf("maior frequencia: %d (%d vezes)\n", elementoMaior, maiorFreq);
    printf("menor frequencia: %d (%d vezes)\n", elementoMenor, menorFreq);
}
