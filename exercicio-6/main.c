// Vamos montar um programa de gestão de contatos;
// a. Crie um tipo novo, baseado em uma struct, que guardará os dados do contato (nome, telefone, email). 
// Use os tipos primitivos que você considerar adequados para os campos dessa struct;
// b. Instancie o container de dados usando esse seu novo tipo;
// c. Implemente as funcionalidades básicas, no estilo das listas, para inserir, remover, buscar e detectar o fim da lista de contatos
// d. Implemente as funcionalidades clássicas de uma agenda de contatos, em funções individuais:
//  1- Atualizar Nome do contato;
//  2- Atualizar Telefone do contato;
//  3- Atualizar email do contato;
// e. Construa um fluxo de interface em texto, para atuar como front-end para as funcionalidades já construídas;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char nome[100];
    char tel[20];
    char mail[100];
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *inicio;
    int tam;
} Agenda;

void iniciarAgenda(Agenda *ag) {
    ag->inicio = NULL;
    ag->tam = 0;
}

void adicionarContato(Agenda *ag, const char *nome, const char *tel, const char *mail) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(novo->nome, nome);
    strcpy(novo->tel, tel);
    strcpy(novo->mail, mail);
    novo->prox = ag->inicio;
    ag->inicio = novo;
    ag->tam++;
}

Nodo *procurarContato(Agenda *ag, const char *nome) {
    Nodo *atual = ag->inicio;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void removerContato(Agenda *ag, const char *nome) {
    Nodo *ant = NULL, *atual = ag->inicio;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (ant == NULL) {
            ag->inicio = atual->prox;
        } else {
            ant->prox = atual->prox;
        }
        free(atual);
        ag->tam--;
    }
}

void atualizarNome(Nodo *contato, const char *novoNome) {
    strcpy(contato->nome, novoNome);
}

void atualizarTel(Nodo *contato, const char *novoTel) {
    strcpy(contato->tel, novoTel);
}

void atualizarMail(Nodo *contato, const char *novoMail) {
    strcpy(contato->mail, novoMail);
}

int fimAgenda(Nodo *contato) {
    return contato == NULL;
}

void listarContatos(Agenda *ag) {
    Nodo *atual = ag->inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Telefone: %s\n", atual->tel);
        printf("Email: %s\n\n", atual->mail);
        atual = atual->prox;
    }
}

void limparAgenda(Agenda *ag) {
    Nodo *atual = ag->inicio;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    ag->inicio = NULL;
    ag->tam = 0;
}

int main() {
    Agenda ag;
    iniciarAgenda(&ag);
    int op;
    char nome[100], tel[20], mail[100];
    do {
        printf("1. Adicionar contato\n2. Procurar contato\n3. Remover contato\n4. Atualizar nome\n5. Atualizar telefone\n6. Atualizar email\n7. Listar contatos\n8. Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Telefone: ");
                scanf(" %[^\n]", tel);
                printf("Email: ");
                scanf(" %[^\n]", mail);
                adicionarContato(&ag, nome, tel, mail);
                break;
            case 2:
                printf("Nome do contato a procurar: ");
                scanf(" %[^\n]", nome);
                Nodo *encontrado = procurarContato(&ag, nome);
                if (encontrado) {
                    printf("Nome: %s\nTelefone: %s\nEmail: %s\n", encontrado->nome, encontrado->tel, encontrado->mail);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 3:
                printf("Nome do contato a remover: ");
                scanf(" %[^\n]", nome);
                removerContato(&ag, nome);
                break;
            case 4:
                printf("Nome do contato a atualizar: ");
                scanf(" %[^\n]", nome);
                encontrado = procurarContato(&ag, nome);
                if (encontrado) {
                    printf("Novo nome: ");
                    scanf(" %[^\n]", nome);
                    atualizarNome(encontrado, nome);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 5:
                printf("Nome do contato a atualizar: ");
                scanf(" %[^\n]", nome);
                encontrado = procurarContato(&ag, nome);
                if (encontrado) {
                    printf("Novo telefone: ");
                    scanf(" %[^\n]", tel);
                    atualizarTel(encontrado, tel);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 6:
                printf("Nome do contato a atualizar: ");
                scanf(" %[^\n]", nome);
                encontrado = procurarContato(&ag, nome);
                if (encontrado) {
                    printf("Novo email: ");
                    scanf(" %[^\n]", mail);
                    atualizarMail(encontrado, mail);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 7:
                listarContatos(&ag);
                break;
        }
    } while (op != 8);
    limparAgenda(&ag);
    return 0;
}
