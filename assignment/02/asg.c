#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *link;
} node;

typedef struct {
    node *front;
    node *rear;
} linkedListQueue;

// 공백 큐를 생성하는 연산
linkedListQueue *createLQ() {
    linkedListQueue *LQ = (linkedListQueue *) malloc(sizeof(linkedListQueue));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

// 공백큐인지 확인하는 연산
int isEmpty(linkedListQueue *LQ) {
    return LQ->front == NULL;
}

// 큐의 rear에 데이터를 삽입하는 연산
void enQueue(linkedListQueue *LQ, char item) {
    // 노드를 생성하고 값을 세팅
    node *new = (node *) malloc(sizeof(node));
    new->data = item;
    new->link = NULL;

    if (isEmpty(LQ)) { // 공백 큐이면, 삽입 후 1개의 노드만 큐에 존재하므로 front와 rear가 new를 가리키게 된다.
        LQ->front = new;
        LQ->rear = new;
    } else { // 공백 큐가 아니라면, rear의 뒤에 new를 연결하고 rear를 new로 변경
        LQ->rear->link = new;
        LQ->rear = new;
    }
}

char deQueue(linkedListQueue *LQ) {
    if (isEmpty(LQ)) { // 공백 큐인 경우, 삭제가 불가능하므로 널문자 리턴하고 종료
        return '\0';
    }
    // 공백 큐가 아닌 경우, 큐의 첫번째 노드의 데이터를 리턴한다.
    node *old = LQ->front;
    char item = old->data;
    LQ->front = LQ->front->link;
    if (isEmpty(LQ)) { // 삭제 후, 공백 큐가 되었다면 rear도 NULL로 변경
        LQ->rear = NULL;
    }
    free(old);
    return item;
}

char peek(linkedListQueue *LQ) {
    if (isEmpty(LQ)) { // 공백 큐인 경우, 조회가 불가능하므로 널문자 리턴하고 종료
        return '\0';
    }
    return LQ->front->data; // 공백 큐가 아닌 경우, 첫번째 노드의 데이터를 리턴하고 종료
}

// 문자열의 길이를 구하는 연산
int length(linkedListQueue *LQ) {
    node *temp = LQ->front;
    int cnt = 0;
    while (temp) {
        cnt++;
        temp = temp->link;
    }
    return cnt;
}

// 문자 출력에 해당하는 연산
// 첫 번째 문자와 마지막 문자를 출력하는 연산
void string(linkedListQueue *LQ) {
    node *temp = LQ->front;
    while (temp) {
        printf("%c", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int input(const char *msg, int min, int max) {
    int data;
    while (1) {
        printf("%s", msg);
        scanf("%d%*c", &data);
        if (data < min || data > max) {
            printf("잘못된 입력. 다시 입력하세요.\n\n");
            continue;
        }
        break;
    }
    return data;
}

int main(void) {
    linkedListQueue *LQ = createLQ();
    printf("1) 문자 추가\n2) 문자 제거\n3) 문자열 길이 반환\n4) 문자열 반환\n\n");
    for (int i = 0; i < 10; i++) {
        int opt = input("번호를 입력하세요: ", 1, 4);
        char ch;
        switch (opt) {
            case 1: // 문자 추가
                printf("추가할 문자를 입력하세요: ");
                scanf("%c%*c", &ch);
                enQueue(LQ, ch);
                break;
            case 2: // 문자 제거
                if (isEmpty(LQ)) {
                    printf("존재하는 문자가 없습니다.\n");
                } else {
                    deQueue(LQ);
                }
                break;
            case 3: // 문자열 길이 반환
                printf("%d\n", length(LQ));
                break;
            case 4: // 문자 출력
                printf("첫 번째 문자: %c 마지막 문자: %c\n", LQ->front->data, LQ->rear->data);
                break;
        }
        if (i != 9)
            printf("\n");
    }
    printf("완성된 문자열: ");
    string(LQ);
    return 0;
}