#include <stdio.h>
#include <stdlib.h>

// qsort
int cmp(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return (x > y) - (x < y);
}

int main() {
    int A, B;
    while (scanf("%d %d", &A, &B) == 2) {
        if (A == 0 && B == 0) break;

        int *alice = (int*) malloc(A * sizeof(int));
        int *beatriz = (int*) malloc(B * sizeof(int));

        for (int i = 0; i < A; i++) scanf("%d", &alice[i]);
        for (int i = 0; i < B; i++) scanf("%d", &beatriz[i]);

        // Eliminando duplicatas usando qsort + varredura
        qsort(alice, A, sizeof(int), cmp);
        qsort(beatriz, B, sizeof(int), cmp);

        int uniqA = 0, uniqB = 0;

        // Remove Alice
        int *setA = (int*) malloc(A * sizeof(int));
        for (int i = 0; i < A; i++) {
            if (i == 0 || alice[i] != alice[i-1]) {
                setA[uniqA++] = alice[i];
            }
        }

        // Remove Beatriz
        int *setB = (int*) malloc(B * sizeof(int));
        for (int i = 0; i < B; i++) {
            if (i == 0 || beatriz[i] != beatriz[i-1]) {
                setB[uniqB++] = beatriz[i];
            }
        }

        // calculo exclusivos 1one1
        int i = 0, j = 0;
        int excluA = 0, excluB = 0;

        while (i < uniqA && j < uniqB) {
            if (setA[i] == setB[j]) {
                i++; j++;
            } else if (setA[i] < setB[j]) {
                excluA++;
                i++;
            } else {
                excluB++;
                j++;
            }
        }
        excluA += (uniqA - i);
        excluB += (uniqB - j);

        int resposta = (excluA < excluB) ? excluA : excluB;
        printf("%d\n", resposta);

        free(alice);
        free(beatriz);
        free(setA);
        free(setB);
    }
    return 0;
}
