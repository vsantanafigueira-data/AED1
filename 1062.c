#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            int *saida = (int*) malloc(n * sizeof(int));
            scanf("%d", &saida[0]);
            if (saida[0] == 0) {
                free(saida);
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) scanf("%d", &saida[i]);

            int *pilha = (int*) malloc(n * sizeof(int));
            int topo = -1;
            int prox = 1;
            int ok = 1;

            for (int i = 0; i < n; i++) {
                int x = saida[i];

                while (prox <= n && (topo == -1 || pilha[topo] != x)) {
                    pilha[++topo] = prox;
                    prox++;
                }

                if (pilha[topo] == x) {
                    topo--;
                } else {
                    ok = 0;
                    break;
                }
            }

            if (ok) printf("Yes\n");
            else printf("No\n");

            free(pilha);
            free(saida);
        }
    }

    return 0;
}
