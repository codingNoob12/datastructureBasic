#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10001

typedef int element;

typedef struct {
    element arr[MAX];
    int front;
    int rear;
    int size;
} Queue;

void QueueInit(Queue *q);

int isEmpty(Queue *q);

void enqueue(Queue *q, element item);

element dequeue(Queue *q);

int main(void) {
    int n;
    scanf("%d", &n);

    Queue *q = (Queue *) malloc(sizeof(Queue));
    QueueInit(q);

    for (int i = 0; i < n; i++) {
        char s[6];
        int data;
        scanf("%s", s);

        if (!strcmp(s, "push")) {
            scanf("%d", &data);
            enqueue(q, data);
        } else if (!strcmp(s, "pop")) {
            printf("%d\n", dequeue(q));
        } else if (!strcmp(s, "size")) {
            printf("%d\n", q->size);
        } else if (!strcmp(s, "empty")) {
            printf("%d\n", isEmpty(q));
        } else if (!strcmp(s, "front")) {
            printf("%d\n", q->arr[q->front + 1]);
        } else {
            printf("%d\n", q->arr[q->rear]);
        }
    }

    return 0;
}

void QueueInit(Queue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, element item) {
    q->arr[++q->rear] = item;
    q->size++;
}

element dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    q->size--;
    return q->arr[++q->front];
}