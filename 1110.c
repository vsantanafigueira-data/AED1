#include <stdio.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break; // encerra quando for zero

        int cartas[51]; // vetor com até 50 cartas
        int descartadas[51];
        int i, topo = 0, base = n - 1, qtd_descartadas = 0;

        // preenche a pilha (1 no topo, n na base)
        for (i = 0; i < n; i++) {
            cartas[i] = i + 1;
        }

        // enquanto houver pelo menos 2 cartas
        while (n > 1) {
            // descarta a carta do topo
            descartadas[qtd_descartadas] = cartas[topo];
            qtd_descartadas++;

            // move todas as cartas uma posição para a esquerda
            for (i = 0; i < n - 1; i++) {
                cartas[i] = cartas[i + 1];
            }

            n--; // uma carta foi removida (descartada)

            // move a nova carta do topo para a base
            int carta_base = cartas[0];
            for (i = 0; i < n - 1; i++) {
                cartas[i] = cartas[i + 1];
            }
            cartas[n - 1] = carta_base;
        }

        // imprime as cartas descartadas
        printf("Discarded cards:");
        if (qtd_descartadas > 0) {
            printf(" ");
            for (i = 0; i < qtd_descartadas; i++) {
                printf("%d", descartadas[i]);
                if (i < qtd_descartadas - 1)
                    printf(", ");
            }
        }
        printf("\n");

        // imprime a carta restante
        printf("Remaining card: %d\n", cartas[0]);
    }

    return 0;
}
