#include <stdio.h>
#include <stdlib.h>

// Implementação com 3 estruturas simultâneas: stack, queue e priority queue
// O objetivo é eliminar as que não são possíveis conforme as operações.

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// ---------- Funções auxiliares ----------

// Empilha (push)
void push(Node **top, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *top;
    *top = newNode;
}

// Desempilha (pop) → retorna -1 se vazia
int pop(Node **top) {
    if (*top == NULL) return -1;
    int val = (*top)->value;
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Enfileira (enqueue)
void enqueue(Node **head, Node **tail, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (*tail != NULL)
        (*tail)->next = newNode;
    else
        *head = newNode;
    *tail = newNode;
}

// Desenfileira (dequeue) → retorna -1 se vazia
int dequeue(Node **head, Node **tail) {
    if (*head == NULL) return -1;
    int val = (*head)->value;
    Node *temp = *head;
    *head = (*head)->next;
    if (*head == NULL)
        *tail = NULL;
    free(temp);
    return val;
}

// Insere na fila de prioridade (ordem decrescente)
void insertPQ(Node **pq, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    // Inserção ordenada (maior primeiro)
    if (*pq == NULL || value > (*pq)->value) {
        newNode->next = *pq;
        *pq = newNode;
    } else {
        Node *current = *pq;
        while (current->next != NULL && current->next->value >= value)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Remove o maior (pop da fila de prioridade)
int removePQ(Node **pq) {
    if (*pq == NULL) return -1;
    int val = (*pq)->value;
    Node *temp = *pq;
    *pq = (*pq)->next;
    free(temp);
    return val;
}

// Libera lista
void freeList(Node **head) {
    Node *tmp;
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

// ---------- Programa principal ----------

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Node *stack = NULL;
        Node *queueHead = NULL, *queueTail = NULL;
        Node *pq = NULL;

        int isStack = 1, isQueue = 1, isPQ = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d", &op);

            if (op == 1) {
                scanf("%d", &x);
                // Inserir nas três estruturas
                push(&stack, x);
                enqueue(&queueHead, &queueTail, x);
                insertPQ(&pq, x);
            } else if (op == 2) {
                scanf("%d", &x);
                int s = pop(&stack);
                int q = dequeue(&queueHead, &queueTail);
                int p = removePQ(&pq);

                if (s != x) isStack = 0;
                if (q != x) isQueue = 0;
                if (p != x) isPQ = 0;
            }
        }

        // Verifica qual estrutura ainda é possível
        if (isStack + isQueue + isPQ == 0)
            printf("impossible\n");
        else if (isStack + isQueue + isPQ > 1)
            printf("not sure\n");
        else if (isStack)
            printf("stack\n");
        else if (isQueue)
            printf("queue\n");
        else
            printf("priority queue\n");

        // Limpa listas
        freeList(&stack);
        freeList(&queueHead);
        freeList(&pq);
    }
    return 0;
}
