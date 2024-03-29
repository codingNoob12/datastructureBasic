#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

typedef struct graphNode {
    int vertex;
    struct graphNode *link;
} graphNode;

typedef struct graphType {
    int n;
    struct graphNode *adjList_H[MAX_VERTEX];
    int visited[MAX_VERTEX];
} graphType;

typedef int element;

typedef struct stackNode {
    int data;
    struct stackNode *link;
} stackNode;

stackNode *top;

int isEmpty() {
    if (top == NULL) {
        return 1;
    }
    return 0;
}

void push(int item) {
    stackNode *temp = (stackNode *) malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

int pop() {
    if (isEmpty()) {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    stackNode *temp = top;
    int item = temp->data;
    top = temp->link;
    free(temp);
    return item;
}

void createGraph(graphType *g) {
    g->n = 0;
    for (int v = 0; v < MAX_VERTEX; v++) {
        g->visited[v] = FALSE;
        g->adjList_H[v] = NULL;
    }
}

void insertVertex(graphType *g, int v) {
    if (((g->n) + 1) > MAX_VERTEX) {
        printf("\n 그래프 정점의 개수를 초과하였습니다!");
        return;
    }
    g->n++;
}

void insertEdge(graphType *g, int u, int v) {
    if (u >= g->n || v >= g->n) {
        printf("\n 그래프에 없는 정점입니다!");
        return;
    }
    graphNode *node = (graphNode *) malloc(sizeof(graphNode));
    node->vertex = v;
    node->link = g->adjList_H[u];
    g->adjList_H[u] = node;
}

void print_adjList(graphType *g) {
    graphNode *p;
    for (int i = 0; i < g->n; i++) {
        printf("\n\t\t정점%c의 인접 리스트", i + 65);
        p = g->adjList_H[i];
        while (p) {
            printf(" -> %c", p->vertex + 65);
            p = p->link;
        }
    }
}

void DFS_adjList(graphType *g, int v) {
    graphNode *w;
    top = NULL;
    push(v);
    g->visited[v] = TRUE;
    printf("%c", v + 65);
    while (!isEmpty()) {
        w = g->adjList_H[v];
        while (w) {
            if (!g->visited[w->vertex]) {
                push(w->vertex);
                g->visited[w->vertex] = TRUE;
                printf(" %c", w->vertex + 65);
                v = w->vertex;
                w = g->adjList_H[v];
            } else {
                w = w->link;
            }
        }
        v = pop();
    }
}

int main(void) {
    int i;
    graphType *G9 = (graphType *) malloc(sizeof(graphType));
    createGraph(G9);

    for (i = 0; i < 7; i++) {
        insertVertex(G9, i);
    }
    insertEdge(G9, 0, 2);
    insertEdge(G9, 0, 1);
    insertEdge(G9, 1, 4);
    insertEdge(G9, 1, 3);
    insertEdge(G9, 1, 0);
    insertEdge(G9, 2, 4);
    insertEdge(G9, 2, 0);
    insertEdge(G9, 3, 6);
    insertEdge(G9, 3, 1);
    insertEdge(G9, 4, 6);
    insertEdge(G9, 4, 2);
    insertEdge(G9, 4, 1);
    insertEdge(G9, 5, 6);
    insertEdge(G9, 6, 5);
    insertEdge(G9, 6, 4);
    insertEdge(G9, 6, 3);
    printf("\n G9의 인접 리스트 ");
    print_adjList(G9);

    printf("\n\n////////////////\n\n깊이 우선 탐색 >> ");
    DFS_adjList(G9, 0);
    return 0;
}