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

int testPair(char *exp);

int main(void) {
    char *express = "{(A+B)-3]*5+[{cos(x+y)+7}-1]*4";
//    char *express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
    printf("%s", express);
    if (testPair(express) == 1) {
        printf("\n\n수식의 괄호가 맞게 사용되었습니다!\n");
    } else {
        printf("\n\n수식의 괄호가 틀렸습니다!\n");
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

int testPair(char *exp) {
    char symbol, open_pair;
    int i, length = strlen(exp);
    top = NULL;
    for (i = 0; i < length; i++) {
        symbol = exp[i];
        switch (symbol) {
            case '(':
            case '{':
            case '[':
                push(symbol);
                break;
            case ')':
            case '}':
            case ']':
                if (top == NULL) {
                    return 0;
                }
                open_pair = pop();
                if ((open_pair == '(' && symbol == ')') ||
                    (open_pair == '{' && symbol == '}') ||
                    (open_pair == '[' && symbol == ']')) {

                } else {
                    return 0;
                }
        }
    }
    if (top == NULL) {
        return 1;
    }
    return 0;
}