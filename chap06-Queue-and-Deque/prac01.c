#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 4

typedef char element;
typedef struct {
    element queue[Q_SIZE];
    int front, rear;
} QueueType;

QueueType *createQueue() {
    QueueType *Q = (QueueType *) malloc(sizeof(QueueType));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int isEmpty(QueueType *Q) {
    if (Q->front == Q->rear) {
        printf("Queue is empty! ");
        return 1;
    }
    return 0;
}

int isFull(QueueType *Q) {
    if (Q->rear == Q_SIZE - 1) {
        printf("Queue is full! ");
        return 1;
    }
    return 0;
}

void enQueue(QueueType *Q, element item) {
    if (isFull(Q)) {
        return;
    }
    Q->queue[++Q->rear] = item;
}

element deQueue(QueueType *Q) {
    if (isEmpty(Q)) {
        return '\0';
    }
    return Q->queue[++Q->front];
}

element peek(QueueType *Q) {
    if (isEmpty(Q)) {
        return '\0';
    }
    return Q->queue[Q->front + 1];
}

void printQ(QueueType *Q) {
    printf("Queue : [");
    for (int i = Q->front + 1; i <= Q->rear; i++) {
        printf("%3c", Q->queue[i]);
    }
    printf("]");
}

int main(void) {
    QueueType *Q = createQueue();
    element item;
    printf("***** 순차 큐 연산 *****\n\n");

    printf("삽입 A>> ");
    enQueue(Q, 'A');
    printQ(Q);
    printf("\n");

    printf("삽입 B>> ");
    enQueue(Q, 'B');
    printQ(Q);
    printf("\n");

    printf("삽입 C>> ");
    enQueue(Q, 'C');
    printQ(Q);

    item = peek(Q);
    printf("\tpeek item : %c\n\n", item);

    printf("삭제  >> ");
    item = deQueue(Q);
    printQ(Q);
    printf("\t삭제 데이터: %c\n", item);

    printf("삭제  >> ");
    item = deQueue(Q);
    printQ(Q);
    printf("\t\t삭제 데이터: %c\n", item);

    printf("삭제  >> ");
    item = deQueue(Q);
    printQ(Q);
    printf("\t\t\t삭제 데이터: %c\n", item);

    printf("삽입 D>> ");
    enQueue(Q, 'D');
    printQ(Q);
    printf("\n");

    printf("삽입 E>> ");
    enQueue(Q, 'E');
    printQ(Q);
    printf("\n");

    return 0;
}