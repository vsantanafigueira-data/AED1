#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *n = (No*) malloc(sizeof(No));
        n->valor = valor;
        n->esq = n->dir = NULL;
        return n;
    }
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void pre_ordem(No *raiz, int *primeiro) {
    if (raiz == NULL) return;
    if (*primeiro) {
        printf("%d", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %d", raiz->valor);
    }
    pre_ordem(raiz->esq, primeiro);
    pre_ordem(raiz->dir, primeiro);
}

void in_ordem(No *raiz, int *primeiro) {
    if (raiz == NULL) return;
    in_ordem(raiz->esq, primeiro);
    if (*primeiro) {
        printf("%d", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %d", raiz->valor);
    }
    in_ordem(raiz->dir, primeiro);
}

void pos_ordem(No *raiz, int *primeiro) {
    if (raiz == NULL) return;
    pos_ordem(raiz->esq, primeiro);
    pos_ordem(raiz->dir, primeiro);
    if (*primeiro) {
        printf("%d", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %d", raiz->valor);
    }
}

void liberar(No *raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int casos, n, v;
    scanf("%d", &casos);

    for (int c = 1; c <= casos; c++) {
        scanf("%d", &n);

        No *raiz = NULL;

        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            raiz = inserir(raiz, v);
        }

        printf("Case %d:\n", c);

        int primeiro = 1;
        printf("Pre.: ");
        pre_ordem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        in_ordem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        pos_ordem(raiz, &primeiro);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
