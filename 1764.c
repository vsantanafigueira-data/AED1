#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

Edge edges[50000];

int parent[40000], rankUF[40000];

int findSet(int x) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rankUF[a] < rankUF[b]) parent[a] = b;
        else if (rankUF[b] < rankUF[a]) parent[b] = a;
        else {
            parent[b] = a;
            rankUF[a]++;
        }
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int M, N;

    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        // Inicializa Union-Find
        for (int i = 0; i < M; i++) {
            parent[i] = i;
            rankUF[i] = 0;
        }

        // Ordena arestas por peso
        qsort(edges, N, sizeof(Edge), cmp);

        long long mstSum = 0;
        int edgesUsed = 0;

        // Kruskal
        for (int i = 0; i < N && edgesUsed < M - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            if (findSet(u) != findSet(v)) {
                unionSet(u, v);
                mstSum += w;
                edgesUsed++;
            }
        }

        printf("%lld\n", mstSum);
    }

    return 0;
}
