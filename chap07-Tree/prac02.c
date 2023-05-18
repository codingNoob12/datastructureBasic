#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {
    char key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode *searchBST(treeNode *root, char x) {
    treeNode *p = root;
    while (p != NULL) {
        if (x == p->key) {
            return p;
        }
        p->key > x ? (p = p->left) : (p = p->right);
    }
    printf("\n 찾는 키가 없습니다!");
    return p;
}

treeNode *insertNode(treeNode *p, char x) {
    if (p == NULL) {
        treeNode *newNode = (treeNode *) malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (x == p->key) {
        printf("\n 이미 같은 키가 있습니다!\n");
        return p;
    }
    x < p->key ? (p->left = insertNode(p->left, x)) : (p->right = insertNode(p->right, x));

    return p;
}


void deleteNode(treeNode *root, char key) {
    treeNode *parent, *p, *successor, *successor_parent;
    treeNode *child;

    parent = NULL;
    p = root;
    while (p != NULL && p->key != key) {
        parent = p;
        key < p->key ? (p = p->left) : (p = p->right);
    }

    if (p == NULL) {
        printf("\n 찾는 키가 이진 트리에 없습니다!!");
        return;
    }

    if (p->left == NULL && p->right == NULL) {
        if (parent != NULL) {
            parent->left == p ? (parent->left = NULL) : (parent->right = NULL);
        } else {
            root = NULL;
        }
    } else if (p->left == NULL || p->right == NULL) {
        p->left != NULL ? (child = p->left) : (child = p->right);

        if (parent != NULL) {
            parent->left == p ? (parent->left = child) : (parent->right = child);
        } else {
            root = child;
        }
    } else {
        successor_parent = p;
        successor = p->left;
        while (successor->right != NULL) {
            successor_parent = successor;
            successor = successor->right;
        }
        // 삭제할 노드의 왼쪽 자식이 후계자인 경우도 고려해야됨 => 부모의 left가 후계자인지 확인!!
        // 후계자의 왼쪽은 있을 수 있음, 오른쪽은 없음!!
        successor_parent->left == successor ? (successor_parent->left = successor->left)
                                            : (successor_parent->right = successor->left);
        p->key = successor->key;
        p = successor;
    }

    free(p);
}

void displayInorder(treeNode *root) {
    if (root == NULL) {
        return;
    }
    displayInorder(root->left);
    printf("%c_", root->key);
    displayInorder(root->right);
}

void menu() {
    printf("\n*----------------*");
    printf("\n\t1: 트리 출력");
    printf("\n\t2: 문자 삽입");
    printf("\n\t3: 문자 삭제");
    printf("\n\t4: 문자 검색");
    printf("\n\t5: 종료");
    printf("\n*----------------*");
    printf("\n메뉴입력 >> ");
}

int main(void) {
    treeNode *root = NULL;
    treeNode *foundedNode = NULL;
    char choice, key;

    root = insertNode(root, 'G');
    insertNode(root, 'I');
    insertNode(root, 'H');
    insertNode(root, 'D');
    insertNode(root, 'B');
    insertNode(root, 'M');
    insertNode(root, 'N');
    insertNode(root, 'A');
    insertNode(root, 'J');
    insertNode(root, 'E');
    insertNode(root, 'Q');

    while (1) {
        menu();
        scanf("%c%*c", &choice);

        switch (choice - '0') {
            case 1:
                printf("\t[이진 트리 출력] ");
                displayInorder(root);
                printf("\n");
                break;

            case 2:
                printf("삽입할 문자를 입력하세요 : ");
                scanf("%c%*c", &key);
                insertNode(root, key);
                break;

            case 3:
                printf("삭제할 문자를 입력하세요 : ");
                scanf("%c%*c", &key);
                deleteNode(root, key);
                break;

            case 4:
                printf("찾을 문자를 입력하세요 : ");
                scanf("%c%*c", &key);
                foundedNode = searchBST(root, key);
                if (foundedNode != NULL) {
                    printf("\n %c를 찾았습니다!\n", foundedNode->key);
                } else {
                    printf("\n 문자를 찾지 못했습니다.\n");
                }
                break;

            case 5:
                return 0;

            default:
                printf("없는 메뉴입니다. 메뉴를 다시 선택하세요!\n");
                break;
        }
    }
}


