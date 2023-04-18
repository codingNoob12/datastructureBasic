#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct stackNode {
    element data;
    struct stackNode *link;
} stackNode;

stackNode *top;

int isEmpty();

void push(element item);

element pop();

element peek();

void printStack();

int testVPS(char *exp);

int main(void) {
    int t;
    char ps[100];
    scanf("%d%*c", &t);
    for (int i = 0; i < t; i++) {
        gets(ps);
        if (testVPS(ps)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

int isEmpty() {
    return top == NULL;
}

void push(element item) {
    stackNode *new = (stackNode *) malloc(sizeof(stackNode));
    new->data = item;
    new->link = top;
    top = new;
}

element pop() {
    if (isEmpty()) {
        printf("\n\n Stack is Empty!\n");
        exit(0);
    }
    stackNode *temp = top;
    element res = temp->data;
    top = top->link;
    free(temp);
    return res;
}

element peek() {
    if (isEmpty()) {
        printf("\n\n Stack is Empty!\n");
        exit(0);
    }
    return top->data;
}

void printStack() {
    stackNode *p = top;
    printf("\nSTACK [ ");
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("]");
}

int testVPS(char *exp) {
    char symbol;
    int i, length = strlen(exp);
    top = NULL;
    for (i = 0; i < length; i++) {
        symbol = exp[i];
        if (symbol == '(') {
            push(symbol);
            continue;
        }
        if (top == NULL) {
            return 0;
        }
        pop();
    }
    if (top == NULL) {
        return 1;
    }
    return 0;
}