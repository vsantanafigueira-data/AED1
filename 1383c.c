//Sudoku com alocação DINÂMICA

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n <= 0) {
        scanf("%d", &n);
    }

    for (int k = 1; k <= n; k++) {
        // aloca a matriz 9x9 dinamicamente
        int **mat = (int **) malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            mat[i] = (int *) malloc(9 * sizeof(int));
        }

        int valido = 1; // assume válido

        // leitura da matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        // verificar linhas
        for (int i = 0; i < 9 && valido; i++) {
            int *cont = (int *) calloc(10, sizeof(int));

            for (int j = 0; j < 9; j++) {
                int val = mat[i][j];
                if (val < 1 || val > 9 || cont[val] > 0) {
                    valido = 0;
                    break;
                }
                cont[val]++;
            }
            free(cont);
        }

        // verificar colunas
        for (int j = 0; j < 9 && valido; j++) {
            int *cont = (int *) calloc(10, sizeof(int));

            for (int i = 0; i < 9; i++) {
                int val = mat[i][j];
                if (val < 1 || val > 9 || cont[val] > 0) {
                    valido = 0;
                    break;
                }
                cont[val]++;
            }
            free(cont);
        }

        // verificar blocos 3x3
        for (int bx = 0; bx < 9 && valido; bx += 3) {
            for (int by = 0; by < 9 && valido; by += 3) {
                int *cont = (int *) calloc(10, sizeof(int));

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
                free(cont);
            }
        }

        // saída
        printf("Instancia %d\n", k);
        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        // liberar matriz
        for (int i = 0; i < 9; i++) {
            free(mat[i]);
        }
        free(mat);
    }

    return 0;
}
