// Utilize uma lista estática como a que implementamos em sala de aula, com 50 slots;
// a. Crie uma nova função de inserção de dados na lista de inteiros, garantindo que o novo elemento x seja inserido antes do valor 
// maior que ele e depois do valor menor que ele, para que a lista sempre fique em ordem crescente;
// b. Crie uma outra função que garanta a inserção de números em ordem decrescente. Inspire-se na letra anterior;

#include <stdio.h>
#include <string.h>

typedef struct {
    int valores[50];
    int tamanho;
} ListaEstatica;

void inserirCrescente(ListaEstatica *lista, int elem) {
    int i = lista->tamanho;
    while (i > 0 && lista->valores[i - 1] > elem) {
        lista->valores[i] = lista->valores[i - 1];
        i--;
    }
    lista->valores[i] = elem;
    lista->tamanho++;
}

void inserirDecrescente(ListaEstatica *lista, int elem) {
    int i = lista->tamanho;
    while (i > 0 && lista->valores[i - 1] < elem) {
        lista->valores[i] = lista->valores[i - 1];
        i--;
    }
    lista->valores[i] = elem;
    lista->tamanho++;
}