#include <stdio.h>
#include <stdlib.h>

typedef int element;
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

int main(void) {
    printf("\n** 연결 스택 연산 **\n");
    element item;
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();
    item = peek();
    printStack();
    printf("\tpeek => %d", item);
    item = pop();
    printStack();
    printf("\tpop  => %d", item);
    item = pop();
    printStack();
    printf("\t\tpop  => %d", item);
    item = pop();
    printStack();
    printf("\t\tpop  => %d", item);
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