#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define INF 1000000000
#define MAX 501

typedef struct {
    int v, w;
} Edge;

Edge graph[MAX * MAX];
int head[MAX], nextEdge[MAX * MAX], edgeCnt;

int N, E;

int graphDir[MAX][MAX];
int graphRev[MAX][MAX];
int visited[MAX];
int order[MAX], ordTop;
int comp[MAX], compId;

void addEdge(int u, int v, int w) {
    graph[edgeCnt].v = v;
    graph[edgeCnt].w = w;
    nextEdge[edgeCnt] = head[u];
    head[u] = edgeCnt++;
}

void dfs1(int u) {
    visited[u] = 1;
    for (int v = 1; v <= N; v++)
        if (graphDir[u][v] && !visited[v])
            dfs1(v);
    order[ordTop++] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    comp[u] = compId;
    for (int v = 1; v <= N; v++)
        if (graphRev[u][v] && !visited[v])
            dfs2(v);
}

//
// Dijkstra com heap mínimo
//
typedef struct {
    int node, dist;
} Node;

Node heap[200000];
int heapSize;

void push(Node x) {
    heap[++heapSize] = x;
    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        Node t = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = t;
        i /= 2;
    }
}

Node pop() {
    Node ret = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int l = i * 2, r = i * 2 + 1, small = i;
        if (l <= heapSize && heap[l].dist < heap[small].dist) small = l;
        if (r <= heapSize && heap[r].dist < heap[small].dist) small = r;
        if (small == i) break;
        Node t = heap[i];
        heap[i] = heap[small];
        heap[small] = t;
        i = small;
    }
    return ret;
}

int dista[MAX];

void dijkstra(int start) {
    for (int i = 1; i <= N; i++) dista[i] = INF;

    heapSize = 0;
    dista[start] = 0;
    push((Node){start, 0});

    while (heapSize) {
        Node top = pop();
        int u = top.node, d = top.dist;
        if (d > dista[u]) continue;

        for (int e = head[u]; e != -1; e = nextEdge[e]) {
            int v = graph[e].v;
            int w = graph[e].w;

            if (d + w < dista[v]) {
                dista[v] = d + w;
                push((Node){v, dista[v]});
            }
        }
    }
}

int main() {

    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        memset(graphDir, 0, sizeof(graphDir));
        memset(graphRev, 0, sizeof(graphRev));

        // Lê arestas
        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            graphDir[X][Y] = H;
            graphRev[Y][X] = H;
        }

        // 1) Encontrar SCCs (Kosaraju)
        memset(visited, 0, sizeof(visited));
        ordTop = 0;
        for (int i = 1; i <= N; i++)
            if (!visited[i])
                dfs1(i);

        memset(visited, 0, sizeof(visited));
        compId = 0;
        for (int i = ordTop - 1; i >= 0; i--) {
            int u = order[i];
            if (!visited[u]) {
                compId++;
                dfs2(u);
            }
        }

        // 2) Recriar lista de adjacência
        memset(head, -1, sizeof(head));
        edgeCnt = 0;

        // Arestas reais
        for (int u = 1; u <= N; u++)
            for (int v = 1; v <= N; v++)
                if (graphDir[u][v])
                    addEdge(u, v, graphDir[u][v]);

        // Arestas de peso 0 dentro da mesma SCC
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (comp[i] == comp[j] && i != j)
                    addEdge(i, j, 0);

        // 3) Responde consultas com Dijkstra
        int K;
        scanf("%d", &K);
        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);

            dijkstra(O);

            if (dista[D] >= INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dista[D]);
        }

        printf("\n");
    }

    return 0;
}
