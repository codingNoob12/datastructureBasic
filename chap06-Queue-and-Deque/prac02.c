#include <stdio.h>
#include <stdlib.h>

#define CQ_SIZE 4

typedef char element;
typedef struct {
    element queue[CQ_SIZE];
    int front, rear;
} QueueType;

QueueType *createQueue() {
    QueueType *CQ = (QueueType *) malloc(sizeof(QueueType));
    CQ->front = 0;
    CQ->rear = 0;
    return CQ;
}

int isEmpty(QueueType *CQ) {
    if (CQ->front == CQ->rear) {
        printf("Queue is empty! ");
        return 1;
    }
    return 0;
}

int isFull(QueueType *CQ) {
    if (CQ->front == (CQ->rear + 1) % CQ_SIZE) {
        printf("Queue is full! ");
        return 1;
    }
    return 0;
}

void enQueue(QueueType *CQ, element item) {
    if (isFull(CQ)) {
        return;
    }
    CQ->rear = (CQ->rear + 1) % CQ_SIZE;
    CQ->queue[CQ->rear] = item;
}

element deQueue(QueueType *CQ) {
    if (isEmpty(CQ)) {
        return '\0';
    }
    CQ->front = (CQ->front + 1) % CQ_SIZE;
    return CQ->queue[CQ->front];
}

element peek(QueueType *CQ) {
    if (isEmpty(CQ)) {
        return '\0';
    }
    return CQ->queue[(CQ->front + 1) % CQ_SIZE];
}

void printQ(QueueType *CQ) {
    printf("Circular Queue : [");
    int first = (CQ->front + 1) % CQ_SIZE;
    int last = (CQ->rear + 1) % CQ_SIZE;
    int i = first;
    while (i != last) {
        printf("%3c", CQ->queue[i]);
        i = (i + 1) % CQ_SIZE;
    }
    printf(" ]");
}

int main(void) {
    QueueType *Q = createQueue();
    element item;
    printf("***** 원형 큐 연산 *****\n\n");

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
    printf("\t\t삭제 데이터: %c\n", item);

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