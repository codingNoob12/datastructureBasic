#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

element evalPostfix(char *exp);

int main(void) {
    int result;
    char *express = "35*62/-";
    printf("후위 표기식 : %s", express);

    result = evalPostfix(express);
    printf("\n\n연산 결과 => %d\n", result);
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

element evalPostfix(char *exp) {
    int opr1, opr2, value, i = 0;
    int length = strlen(exp);
    char symbol;
    top = NULL;
    for (i = 0; i < length; i++) {
        symbol = exp[i];
        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
            value = symbol - '0';
            push(value);
            continue;
        }
        opr2 = pop();
        opr1 = pop();
        switch (symbol) {
            case '+':
                push(opr1 + opr2);
                break;
            case '-':
                push(opr1 - opr2);
                break;
            case '*':
                push(opr1 * opr2);
                break;
            case '/':
                push(opr1 / opr2);
                break;
        }
    }
    return pop();
}