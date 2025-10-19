//Funcionamento da pilha utilizando vetores ao invés de malloc (primitivo)
#include <stdio.h>
#include <string.h>

#define MAX 1000  // tamanho máximo que a expressão pode ter

int main() {
    char expressao[MAX];
    
    // lê várias expressões até acabar o arquivo (entrada)
    while (fgets(expressao, MAX, stdin) != NULL) {
        char pilha[MAX];  // vetor que vai funcionar como uma pilha
        int topo = -1;    // topo da pilha começa em -1 (vazia)
        int i;
        int correto = 1;  // começa assumindo que está correto

        // percorre todos os caracteres da expressão
        for (i = 0; expressao[i] != '\0'; i++) {
            
            // se for um parêntese abrindo, empilha
            if (expressao[i] == '(') {
                topo++;               // sobe o topo
                pilha[topo] = '(';    // guarda o parêntese na pilha
            } 
            
            // se for um parêntese fechando
            else if (expressao[i] == ')') {
                // se não tiver nada na pilha, é erro (fechou sem abrir)
                if (topo == -1) {
                    correto = 0;
                    break;  // para de verificar
                } else {
                    topo--;  // desempilha (remove o último '(')
                }
            }
        }

        // se ainda ficou parêntese sem fechar, está incorreto
        if (topo != -1) {
            correto = 0;
        }

        // mostra o resultado
        if (correto == 1)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
