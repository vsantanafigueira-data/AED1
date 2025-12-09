#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int w;
} Edge;

Edge edges[200005];
int parent[200005], rankUF[200005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rankUF[a] < rankUF[b])
            parent[a] = b;
        else if (rankUF[b] < rankUF[a])
            parent[b] = a;
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
    int m, n;
    while (scanf("%d %d", &m, &n) && (m || n)) {

        long long total = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total += edges[i].w;
        }

        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rankUF[i] = 0;
        }

        qsort(edges, n, sizeof(Edge), cmp);

        long long mst = 0;

        for (int i = 0; i < n; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            if (find(u) != find(v)) {
                unite(u, v);
                mst += w;
            }
        }

        printf("%lld\n", total - mst);
    }

    return 0;
}
