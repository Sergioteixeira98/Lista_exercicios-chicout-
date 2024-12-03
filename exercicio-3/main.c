// Fazer um programa em C que lê uma lista de 20 produtos e de preços e armazena-os em um array do tipo da estrutura abaixo. 
// O programa deve, em seguida, ordenar o vetor em ordem alfabética de nome de produto e inflacionar os produtos cujo valor for menor que 100 em 5%. 
// Por fim, a lista de produtos/preços deve ser impressa. 

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[80];
    float preco;
} Item;

void lerItens(Item itens[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Digite o nome do item %d: ", i + 1);
        scanf(" %[^\n]", itens[i].nome);
        printf("Digite o preco do item %d: ", i + 1);
        scanf("%f", &itens[i].preco);
    }
}

void ordenarItens(Item itens[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(itens[i].nome, itens[j].nome) > 0) {
                Item aux = itens[i];
                itens[i] = itens[j];
                itens[j] = aux;
            }
        }
    }
}

void ajustarPrecos(Item itens[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        if (itens[i].preco < 100) {
            itens[i].preco *= 1.05;
        }
    }
}

void exibirItens(Item itens[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Item: %s, Preco: %.2f\n", itens[i].nome, itens[i].preco);
    }
}

int main() {
    Item itens[20];
    int qtd = 20;

    lerItens(itens, qtd);
    ordenarItens(itens, qtd);
    ajustarPrecos(itens, qtd);
    exibirItens(itens, qtd);

    return 0;
}
