// utilizando lista de adjacência para representar o grafo
#include <stdio.h>
#include <stdlib.h>

#define MAX 10005
#define MAXG 100  // limite de grau

int visitado[MAX];
int ciclo;
int n, m;
int adj[MAX][MAXG];
int grau[MAX];

void dfs(int u) {
    visitado[u] = 1; 

    for (int i = 0; i < grau[u]; i++) {
        int v = adj[u][i];

        if (visitado[v] == 0) {
            dfs(v);
        } else if (visitado[v] == 1) {
            ciclo = 1;
        }
    }

    visitado[u] = 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &n, &m);

        // limpa lixo
        for (int i = 1; i <= n; i++) {
            grau[i] = 0;
            visitado[i] = 0;
            for (int j = 0; j < MAXG; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            // verificação de arestas existentes
            int existe = 0;
            for (int j = 0; j < grau[a]; j++) {
                if (adj[a][j] == b) {
                    existe = 1;
                    break;
                }
            }

            // adiciona apenas se ainda não existir
            if (!existe && grau[a] < MAXG)
                adj[a][grau[a]++] = b;
        }

        ciclo = 0;

        for (int i = 1; i <= n && !ciclo; i++) {
            if (visitado[i] == 0)
                dfs(i);
        }

        printf("%s\n", ciclo ? "SIM" : "NAO");
    }

    return 0;
}
