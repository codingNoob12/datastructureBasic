#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    struct ListNode* llink;
    char data[4];
    struct ListNode* rlink;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList() {
    linkedList_h* DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL->head = NULL;
    return DL;
}

void printList(linkedList_h* DL) {
    listNode* p = DL->head;
    printf("DL=(");
    while(p) {
        printf("%s", p->data);
        p = p->rlink;
        if (p) {
            printf(", ");
        }
    }
    printf(")\n");
}

void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (!DL->head) {
        DL->head = newNode;
        newNode->llink = NULL;
        newNode->rlink = NULL;
        return;
    }
    newNode->rlink = pre->rlink;
    pre->rlink = newNode;
    newNode->llink = pre;
    if (newNode->rlink) {
        newNode->rlink->llink = newNode;
    }
    return;
}

void deleteNode(linkedList_h* DL, listNode* old) {
    if (!DL->head) {
        return;
    }
    if (!old) {
        return;
    }
    old->llink->rlink = old->rlink;
    old->rlink->llink = old->llink;
    free(old);
}

listNode* searchNode(linkedList_h* DL, char* x) {
    listNode* temp = DL->head;
    while (temp) {
        if (!strcmp(temp->data, x)) {
            return temp;
        }
        temp = temp->rlink;
    }
    return temp;
}

int main(void) {
    linkedList_h* DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    printf("(1) 이중 연결 리스트 생성하기!\n");
    printList(DL);
    getchar();

    printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기!\n");
    insertNode(DL, NULL, "월");
    printList(DL);
    getchar();

    printf("(3) 이중 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기!\n");
    listNode* p = searchNode(DL, "월");
    insertNode(DL, p, "수");
    printList(DL);
    getchar();

    printf("(4) 이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기!\n");
    p = searchNode(DL, "수");
    insertNode(DL, p, "금");
    printList(DL);
    getchar();

    printf("(5) 이중 연결 리스트에서 [수] 노드 삭제하기!\n");
    p = searchNode(DL, "수");
    deleteNode(DL, p);
    printList(DL);
    getchar();

    return 0;
}
