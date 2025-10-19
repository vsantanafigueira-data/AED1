#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int X[N];       // vetor
    int *p = X;     // ponteiro que aponta para o início do vetor

    // leitura usando ponteiro
    for (int i = 0; i < N; i++) {
        scanf("%d", (p + i));
    }

    int menor_valor = *p;
    int posicao = 0;

    // busca do menor valor usando apenas ponteiros
    for (int i = 1; i < N; i++) {
        if (*(p + i) < menor_valor) {
            menor_valor = *(p + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    return 0;
}

//duvida: utilizar um array fixo apenas para reserva de memória e o ponteiro acessar ou utilizar um vetor onde será ALOCADO os valores scanneados?
