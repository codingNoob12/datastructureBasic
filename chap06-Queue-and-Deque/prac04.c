#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct DQNode {
    element data;
    struct DQNode *llink;
    struct DQNode *rlink;
} DQNode;

typedef struct {
    DQNode *front, *rear;
} DQueueType;

DQueueType *createDQue() {
    DQueueType *DQ = (DQueueType *) malloc(sizeof(DQueueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

int isEmpty(DQueueType *DQ) {
    if (DQ->front == NULL) {
        printf("\n Linked Queue is empty!\n");
        return 1;
    }
    return 0;
}

void insertFront(DQueueType *DQ, element item) {
    DQNode *new = (DQNode *) malloc(sizeof(DQNode));
    new->data = item;
    new->llink = NULL;
    new->rlink = DQ->front;

    if (DQ->front == NULL) {
        DQ->front = new;
        DQ->rear = new;
        return;
    }
    DQ->front->llink = new;
    DQ->front = new;
}

void insertRear(DQueueType *DQ, element item) {
    DQNode *new = (DQNode *) malloc(sizeof(DQNode));
    new->data = item;
    new->llink = DQ->rear;
    new->rlink = NULL;

    if (DQ->front == NULL) {
        DQ->front = new;
        DQ->rear = new;
        return;
    }
    DQ->rear->rlink = new;
    DQ->rear = new;
}

element deleteFront(DQueueType *DQ) {
    DQNode *old = DQ->front;
    if (isEmpty(DQ)) {
        return '\0';
    }
    element item = old->data;
    if (old->rlink == NULL) {
        DQ->front = NULL;
        DQ->rear = NULL;
    } else {
        DQ->front = old->rlink;
        DQ->front->llink = NULL;
    }
    free(old);
    return item;
}

element deleteRear(DQueueType *DQ) {
    DQNode *old = DQ->rear;
    if (isEmpty(DQ)) {
        return '\0';
    }
    element item = old->data;
    if (old->llink == NULL) {
        DQ->front = NULL;
        DQ->rear = NULL;
    } else {
        DQ->rear = old->llink;
        DQ->rear->rlink = NULL;
    }
    free(old);
    return item;
}

element peekFront(DQueueType *DQ) {
    if (isEmpty(DQ)) {
        return '\0';
    }
    return DQ->front->data;
}

element peekRear(DQueueType *DQ) {
    if (isEmpty(DQ)) {
        return '\0';
    }
    return DQ->rear->data;
}

void printDQ(DQueueType *DQ) {
    DQNode *p = DQ->front;
    printf("DeQue : [");
    while (p != NULL) {
        printf("%3c", p->data);
        p = p->rlink;
    }
    printf(" ]");
}

int main(void) {
    DQueueType *DQ = createDQue();
    element item;
    printf("***** 연결 큐 연산 *****\n\n");

    printf("front 삽입 A>> ");
    insertFront(DQ, 'A');
    printDQ(DQ);
    printf("\n");

    printf("front 삽입 B>> ");
    insertFront(DQ, 'B');
    printDQ(DQ);
    printf("\n");

    printf("rear 삽입 C>> ");
    insertRear(DQ, 'C');
    printDQ(DQ);

    printf("front 삭제  >> ");
    item = deleteFront(DQ);
    printDQ(DQ);
    printf("\t\t삭제 데이터: %c\n", item);

    printf("rear 삭제  >> ");
    item = deleteRear(DQ);
    printDQ(DQ);
    printf("\t삭제 데이터: %c\n", item);

    printf("rear 삽입 D>> ");
    insertRear(DQ, 'D');
    printDQ(DQ);
    printf("\n");

    printf("front 삽입 E>> ");
    insertFront(DQ, 'E');
    printDQ(DQ);
    printf("\n");

    printf("front 삽입 F>> ");
    insertFront(DQ, 'F');
    printDQ(DQ);
    printf("\n");

    item = peekFront(DQ);
    printf("peek Front item : %c\n", item);

    item = peekRear(DQ);
    printf("peek Rear item : %c\n", item);
    return 0;
}