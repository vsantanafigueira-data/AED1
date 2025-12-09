#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char v;
    struct no *esq, *dir;
} No;

No* inserir(No *r, char v){
    if(r == NULL){
        r = (No*)malloc(sizeof(No));
        r->v = v;
        r->esq = r->dir = NULL;
    } else if(v < r->v)
        r->esq = inserir(r->esq, v);
    else
        r->dir = inserir(r->dir, v);
    return r;
}

int busca(No *r, char v){
    if(r == NULL) return 0;
    if(r->v == v) return 1;
    if(v < r->v) return busca(r->esq, v);
    return busca(r->dir, v);
}

int first;

void infixa(No *r){
    if(r==NULL) return;
    infixa(r->esq);
    if(!first) printf(" ");
    printf("%c", r->v);
    first = 0;
    infixa(r->dir);
}

void prefixa(No *r){
    if(r==NULL) return;
    if(!first) printf(" ");
    printf("%c", r->v);
    first = 0;
    prefixa(r->esq);
    prefixa(r->dir);
}

void posfixa(No *r){
    if(r==NULL) return;
    posfixa(r->esq);
    posfixa(r->dir);
    if(!first) printf(" ");
    printf("%c", r->v);
    first = 0;
}

int main(){
    No *raiz = NULL;
    char op[10], x;

    while(scanf("%s", op) != EOF){
        if(strcmp(op, "I") == 0){
            scanf(" %c", &x);
            raiz = inserir(raiz, x);
        }
        else if(strcmp(op, "P") == 0){
            scanf(" %c", &x);
            if(busca(raiz, x)) printf("%c existe\n", x);
            else printf("%c nao existe\n", x);
        }
        else if(strcmp(op, "INFIXA") == 0){
            first = 1;
            infixa(raiz);
            printf("\n");
        }
        else if(strcmp(op, "PREFIXA") == 0){
            first = 1;
            prefixa(raiz);
            printf("\n");
        }
        else if(strcmp(op, "POSFIXA") == 0){
            first = 1;
            posfixa(raiz);
            printf("\n");
        }
    }

    return 0;
}
