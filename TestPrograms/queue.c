#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = q->rear = NULL;
}

bool isEmpty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = x;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    int result = q->front->info;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return result;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    return q->front->info;
}

int main() {
    Queue a, b;
    initializeQueue(&a);
    initializeQueue(&b);
    int eq = 0, size = 0, n;
    bool flag = true;

    while (scanf("%d", &n) == 1) {
        if (n > 0) {
            enqueue(&a, n);
            eq++;
            size++;
        } else {
            enqueue(&b, n);
            eq--;
        }
    }

    if (eq != 0) {
        flag = false;
    } else {
        while (size > 0) {
            if (dequeue(&a) + dequeue(&b) != 0) {
                flag = false;
            }
            size--;
        }
    }

    if (flag) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
