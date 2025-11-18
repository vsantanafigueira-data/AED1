#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char *s = (char *) malloc(1100 * sizeof(char));  // alocação dinâmica
        if (s == NULL) {
            return 1; // erro de memória
        }

        scanf("%s", s);

        int abertos = 0;   // quantidade de '<' encontrados
        int diamantes = 0;

        char *p = s;       // ponteiro para percorrer a string

        while (*p != '\0') {
            if (*p == '<') {
                abertos++;
            } else if (*p == '>') {
                if (abertos > 0) {
                    abertos--;
                    diamantes++;
                }
            }

            p++; // avança o ponteiro
        }

        printf("%d\n", diamantes);

        free(s); // libera memória
    }

    return 0;
}
