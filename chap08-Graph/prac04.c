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

typedef struct QNode {
    int data;
    struct QNode *link;
} QNode;

typedef struct {
    QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue() {
    LQueueType *LQ = (LQueueType *) malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isEmpty(LQueueType *LQ) {
    if (LQ->front == NULL) {
        printf("\n Linked Queue is empty!\n");
        return 1;
    }
    return 0;
}

void enQueue(LQueueType *LQ, int item) {
    QNode *newNode = (QNode *) malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
        return;
    }
    LQ->rear->link = newNode;
    LQ->rear = newNode;
}

int deQueue(LQueueType *LQ) {
    QNode *old = LQ->front;
    if (isEmpty(LQ)) {
        return 0;
    }
    int item = old->data;
    LQ->front = old->link;
    if (LQ->front == NULL) {
        LQ->rear = NULL;
    }
    free(old);
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

void BFS_adjList(graphType *g, int v) {
    graphNode *w;
    LQueueType *Q = createLinkedQueue();
    g->visited[v] = TRUE;
    printf(" %c", v + 65);
    enQueue(Q, v);

    while (!isEmpty(Q)) {
        v = deQueue(Q);
        for (w = g->adjList_H[v]; w; w = w->link) {
            if (!g->visited[w->vertex]) {
                g->visited[w->vertex] = TRUE;
                printf(" %c", w->vertex + 65);
                enQueue(Q, w->vertex);
            }
        }
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

    printf("\n\n////////////////\n\n너비 우선 탐색 >> ");
    BFS_adjList(G9, 0);
    return 0;
}