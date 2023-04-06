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
    if (!L->head) {
        newNode->link = L->head;
        L->head = newNode;
        return;
    }
    if (!pre) {
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
    while (temp->link) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head) {
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

listNode* searchNode(linkedList_h* L, char* x) {
    listNode* temp = L->head;
    while (temp) {
        if (strcmp(temp->data, x) == 0) {
            return temp;
        }
        temp = temp->link;
    }
    return temp;
}

void deleteNode(linkedList_h* L, listNode* p) {
    listNode* pre;
    if (!L->head) {
        return;
    }
    if (!L->head->link) {
        free(L->head);
        L->head = NULL;
        return;
    }
    if (!p) {
        return;
    }
    pre = L->head;
    if (pre == p) {
        L->head = p->link;
    }
    else {
        while (pre->link != p) {
            pre = pre->link;
        }
        pre->link = p->link;
    }
    free(p);
}

int main(void) {
    linkedList_h* L;
    listNode* p;
    L = createLinkedList_h();
    printf("(1) 리스트에 [월], [수], [일] 노드 삽입하기!\n");
    insertLastNode(L, "월");
    insertLastNode(L, "수");
    insertLastNode(L, "일");
    printList(L);
    getchar();

    printf("(2) 리스트에서 [수] 노드 탐색하기!\n");
    p = searchNode(L, "수");
    if (!p) {
        printf("찾는 데이터가 없습니다\n");
    } else {
        printf("[%s]를 찾았습니다\n", p->data);
    }
    getchar();

    printf("(3) 리스트에서 [수] 뒤에 [금] 노드 삽입하기!\n");
    insertMiddleNode(L, p, "금");
    printList(L);
    getchar();

    printf("(4) 리스트에서 [일] 노드 삭제하기!\n");
    p = searchNode(L, "일");
    deleteNode(L, p);
    printList(L);

    freeLinkedList_h(L);

    return 0;
}