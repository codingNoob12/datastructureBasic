#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct QNode {
    element data;
    struct QNode *link;
} QNode;

typedef struct {
    QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue() {
    LQueueType *LQ = (LQueueType *) malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isEmpty(LQueueType *LQ) {
    if (LQ->front == NULL) {
        printf("Queue is empty! ");
        return 1;
    }
    return 0;
}

void enQueue(LQueueType *LQ, element item) {
    QNode *new = (QNode *) malloc(sizeof(QNode));
    new->data = item;
    new->link = NULL;

    if (LQ->front == NULL) {
        LQ->front = new;
        LQ->rear = new;
        return;
    }
    LQ->rear->link = new;
    LQ->rear = new;
}

element deQueue(LQueueType *LQ) {
    if (isEmpty(LQ)) {
        return '\0';
    }
    element item = LQ->front->data;
    QNode *old = LQ->front;
    if (old == NULL) {
        LQ->front = NULL;
        LQ->rear = NULL;
    } else {
        LQ->front = old->link;
    }
    free(old);
    return item;
}

element peek(LQueueType *LQ) {
    if (isEmpty(LQ)) {
        return '\0';
    }
    return LQ->rear->data;
}

void printLQ(LQueueType *LQ) {
    printf("Linked Queue : [");
    QNode *p = LQ->front;
    while (p != NULL) {
        printf("%3c", p->data);
        p = p->link;
    }
    printf(" ]");
}

int main(void) {
    LQueueType *LQ = createLinkedQueue();
    element item;
    printf("***** 연결 큐 연산 *****\n\n");

    printf("삽입 A>> ");
    enQueue(LQ, 'A');
    printLQ(LQ);
    printf("\n");

    printf("삽입 B>> ");
    enQueue(LQ, 'B');
    printLQ(LQ);
    printf("\n");

    printf("삽입 C>> ");
    enQueue(LQ, 'C');
    printLQ(LQ);

    item = peek(LQ);
    printf("\tpeek item : %c\n\n", item);

    printf("삭제  >> ");
    item = deQueue(LQ);
    printLQ(LQ);
    printf("\t삭제 데이터: %c\n", item);

    printf("삭제  >> ");
    item = deQueue(LQ);
    printLQ(LQ);
    printf("\t\t삭제 데이터: %c\n", item);

    printf("삭제  >> ");
    item = deQueue(LQ);
    printLQ(LQ);
    printf("\t\t\t삭제 데이터: %c\n", item);

    printf("삽입 D>> ");
    enQueue(LQ, 'D');
    printLQ(LQ);
    printf("\n");

    printf("삽입 E>> ");
    enQueue(LQ, 'E');
    printLQ(LQ);
    printf("\n");
    return 0;
}