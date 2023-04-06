#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) {
    linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = L->head;
    L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if(L->head == NULL) {
        newNode->link = L->head;
        L->head = newNode;
        return;
    }
    if (pre == NULL) {
        printf("삽입 오류. 프로그램을 종료합니다.\n");
        exit(1);
    }
    newNode->link = pre->link;
    pre->link = newNode;
}

void insertLastNode(linkedList_h* L, char*x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;
    if (L->head == NULL) {
        L->head = newNode;
        return;
    }
    listNode* temp = L->head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

void printList(linkedList_h* L) {
    listNode* p = L->head;
    printf("L=(");
    while (p) {
        printf("%s", p->data);
        p = p->link;
        if (p) {
            printf(", ");
        }
    }
    printf(")\n");
}

int main() {
    linkedList_h* L = createLinkedList_h();
    printf("(1) 공백 리스트 생성하기!\n");
    printList(L);
    printf("(2) 리스트에 [수] 노드 삽입하기!\n");
    insertFirstNode(L, "수");
    printList(L);
    printf("(3) 리스트 마지막에 [금] 노드 삽입하기!\n");
    insertLastNode(L, "금");
    printList(L);
    printf("(4) 리스트 첫번째에 [월] 노드 삽입하기!\n");
    insertFirstNode(L, "월");
    printList(L);
    printf("(5) 리스트 공간을 해제하여 공백리스트로 만들기!\n");
    freeLinkedList_h(L);
    printList(L);

    return 0;
}