#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005

int *adj[MAXN];
int tam[MAXN];
int vis[MAXN];

int ciclo;

void dfs(int u){
    vis[u] = 1;

    for(int i = 0; i < tam[u]; i++){
        int v = adj[u][i];

        if(vis[v] == 1){ 
            ciclo = 1;
            return;
        }
        if(vis[v] == 0){
            dfs(v);
            if(ciclo) return;
        }
    }

    vis[u] = 2;
}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int N, M;
        scanf("%d %d", &N, &M);

        for(int i = 1; i <= N; i++){
            tam[i] = 0;
            vis[i] = 0;

            if(adj[i] != NULL){
                free(adj[i]);
                adj[i] = NULL;
            }

            adj[i] = (int*)malloc(sizeof(int) * (M+1));
        }

        for(int i = 0; i < M; i++){
            int A, B;
            scanf("%d %d", &A, &B);
            adj[A][tam[A]++] = B;
        }

        ciclo = 0;

        for(int i = 1; i <= N; i++){
            if(vis[i] == 0){
                dfs(i);
                if(ciclo) break;
            }
        }

        if(ciclo) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}
