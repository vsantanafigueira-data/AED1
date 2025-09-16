
//CÓDIGO UTILIZANDO VETORES (SIMPLES)
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n <= 0) {
        scanf("%d", &n);
    }

    for (int k = 1; k <= n; k++) {
        int mat[9][9];
        int valido = 1; // assume válido

        // leitura da matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        // verificar linhas
        for (int i = 0; i < 9 && valido; i++) {
            int cont[10];
            for (int t = 0; t < 10; t++) cont[t] = 0;

            for (int j = 0; j < 9; j++) {
                int val = mat[i][j];
                if (val < 1 || val > 9 || cont[val] > 0) {
                    valido = 0;
                    break;
                }
                cont[val]++;
            }
        }

        // verificar colunas
        for (int j = 0; j < 9 && valido; j++) {
            int cont[10];
            for (int t = 0; t < 10; t++) cont[t] = 0;

            for (int i = 0; i < 9; i++) {
                int val = mat[i][j];
                if (val < 1 || val > 9 || cont[val] > 0) {
                    valido = 0;
                    break;
                }
                cont[val]++;
            }
        }

        // verificar blocos 3x3
        for (int bx = 0; bx < 9 && valido; bx += 3) {
            for (int by = 0; by < 9 && valido; by += 3) {
                int cont[10];
                for (int t = 0; t < 10; t++) cont[t] = 0;

                for (int i = bx; i < bx + 3; i++) {
                    for (int j = by; j < by + 3; j++) {
                        int val = mat[i][j];
                        if (val < 1 || val > 9 || cont[val] > 0) {
                            valido = 0;
                            break;
                        }
                        cont[val]++;
                    }
                }
            }
        }

        // saída
        printf("Instancia %d\n", k);
        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
