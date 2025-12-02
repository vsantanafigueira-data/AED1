#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No* inserir(No *r, int v){
    if (r == NULL){
        r = (No*) malloc(sizeof(No));
        r->valor = v;
        r->esq = r->dir = NULL;
        return r;
    }
    if (v < r->valor) r->esq = inserir(r->esq, v);
    else r->dir = inserir(r->dir, v);
    return r;
}

void inorder(No *r){
    if (!r) return;
    inorder(r->esq);
    printf("%d ", r->valor);
    inorder(r->dir);
}

void liberar(No *r){
    if (!r) return;
    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

int main(){
    int nc;
    scanf("%d", &nc);

    while (nc--){
        int n, h;
        scanf("%d", &n);

        No *raiz = NULL;

        for (int i = 0; i < n; i++){
            scanf("%d", &h);
            raiz = inserir(raiz, h);
        }

        inorder(raiz);
        printf("\n");

        liberar(raiz);
    }

    return 0;
}
 