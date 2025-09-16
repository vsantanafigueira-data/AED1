//alocação dinâmica

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    // aloca dinamicamente espaço para N inteiros
    int *p = (int *) malloc(N * sizeof(int));
    if (p == NULL) {
        return 1;
    }

    // leitura usando ponteiro
    for (int i = 0; i < N; i++) {
        scanf("%d", (p + i));
    }

    int menor_valor = *p;
    int posicao = 0;

    // busca do menor valor
    for (int i = 1; i < N; i++) {
        if (*(p + i) < menor_valor) {
            menor_valor = *(p + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    // libera memória
    free(p);

    return 0;
}
