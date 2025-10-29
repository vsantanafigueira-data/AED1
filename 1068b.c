//pilha com lista encadeada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char c;
    struct No* prox;
} No;

void push(No **top, char ch) {
    No *novo = malloc(sizeof(No));
    if (!novo) exit(1);
    novo->c = ch;
    novo->prox = *top;
    *top = novo;
}

int pop(No **top) {
    if (*top == NULL) return 0;
    No *t = *top;
    *top = t->prox;
    free(t);
    return 1;
}

int isEmpty(No *top) { return top == NULL; }

void freeStack(No **top) {
    while (*top) {
        No *t = *top;
        *top = t->prox;
        free(t);
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    getchar(); // consome '\n' após o número

    char line[2005];
    for (int i = 0; i < N; ++i) {
        if (!fgets(line, sizeof(line), stdin)) line[0] = '\0';
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';

        No *stack = NULL;
        int ok = 1;

        for (char *p = line; *p != '\0'; ++p) {
            if (*p == '(') push(&stack, '(');
            else if (*p == ')') {
                if (!pop(&stack)) { ok = 0; break; } // fecha sem abrir
            }
        }

        if (!isEmpty(stack)) ok = 0; // ainda há abertos sem fechar
        printf("%s\n", ok ? "correct" : "incorrect");
        freeStack(&stack);
    }

    return 0;
}