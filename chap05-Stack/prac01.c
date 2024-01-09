#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty();

int isFull();

void push(element item);

element pop();

element peek();

void printStack();

int main(void) {
    printf("\n** 순차 스택 연산 **\n");
    element res;
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();
    res = peek();
    printStack();
    printf("\tpeek => %d", res);
    res = pop();
    printStack();
    printf("\tpop => %d", res);
    res = pop();
    printStack();
    printf("\tpop => %d", res);
    res = pop();
    printStack();
    printf("\tpop => %d", res);
    return 0;
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == STACK_SIZE - 1;
}

void push(element item) {
    if (isFull()) {
        printf("\n\n Stack is Full!\n");
        return;
    }
    stack[++top] = item;
}

element pop() {
    if (isEmpty()) {
        printf("\n\n Stack is Empty!\n");
        exit(1);
    }
    return stack[top--];
}

element peek() {
    if (isEmpty()) {
        printf("\n\n Stack is Empty!\n");
        exit(1);
    }
    return stack[top];
}

void printStack() {
    printf("\nSTACK [");
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
    }
    printf("]");
}