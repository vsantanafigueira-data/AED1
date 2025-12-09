#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 200003  // número primo para reduzir colisões

typedef struct No {
    char *texto;
    struct No *prox;
} No;

No *tabela[TAM_TABELA];

// Função hash djb2
unsigned long hash(const char *str) {
    unsigned long h = 5381;
    int c;
    while ((c = *str++))
        h = ((h << 5) + h) + c; 
    return h % TAM_TABELA;
}

// Insere no conjunto. Retorna 1 se for novo, 0 se já existia.
int inserir(const char *s) {
    unsigned long h = hash(s);
    No *atual = tabela[h];

    // Verifica se já existe
    while (atual) {
        if (strcmp(atual->texto, s) == 0)
            return 0;  // repetido
        atual = atual->prox;
    }

    // Inserir novo elemento
    No *novo = malloc(sizeof(No));
    novo->texto = strdup(s);
    novo->prox = tabela[h];
    tabela[h] = novo;

    return 1;
}

int main() {
    char buffer[1000005];
    int distintos = 0;

    // Ler cada linha até EOF
    while (fgets(buffer, sizeof(buffer), stdin)) {
        
        // Remover \n do final
        int tam = strlen(buffer);
        if (tam > 0 && buffer[tam - 1] == '\n')
            buffer[tam - 1] = '\0';

        // Se inserir for novo → incrementa contador
        if (inserir(buffer))
            distintos++;
    }

    printf("%d\n", distintos);
    return 0;
}
