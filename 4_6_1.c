#include <stdio.h>
#include <stdlib.h>

//lista encadeada sem cabeça é uma lista ligada onde o ponteiro inicial aponta diretamente para o primeiro nó da lista.
//buscaeremove : função que irá buscar um elemento X na lista e removê-lo se encontrado.
//sem cabeça : não existe um nó adicional no início da lista para facilitar operações.

typedef struct No {
    int valor;
    struct No *prox;
} No;

int BuscaERemove (No **inicio, int valor){
    No *atual = *inicio;
    No *anterior = NULL;

    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        return 0; // valor não encontrado
    }

    if(anterior == NULL){
        *inicio = atual->prox; // remove o primeiro nó
    } else {
        anterior->prox = atual->prox; // remove nó do meio ou fim
    }
    free(atual);
    return 1; // valor removido com sucesso
}

void InsereInicio(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *inicio;
    *inicio = novo;
}
void ImprimeLista(No *inicio) {
    while (inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n");
}

int main() {
    No *lista = NULL;

    InsereInicio(&lista, 3);
    InsereInicio(&lista, 2);
    InsereInicio(&lista, 1); // Lista: 1 -> 2 -> 3

    ImprimeLista(lista); // Saída: 1 2 3

    BuscaERemove(&lista, 2);
    ImprimeLista(lista); // Saída: 1 3

    BuscaERemove(&lista, 1);
    ImprimeLista(lista); // Saída: 3

    BuscaERemove(&lista, 5); // Não existe
    ImprimeLista(lista); // Saída: 3

    return 0;
}