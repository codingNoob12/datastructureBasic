#include <stdio.h>

typedef struct
{
    char name[50];
    char auth[50];
    int price;
} book;


int main(void) {
    book book1 = {"HTML과 CSS", "홍길동", 28000};
    book book2 = {"C로 배우는 쉬운 자료구조 기초", "이지영", 27000};

    printf("첫 번째 책의 제목은 %s이고,\n저자는 %s이며,\n가격은 %d원입니다.\n\n", book1.name, book1.auth, book1.price);
    printf("두 번째 책의 제목은 %s이고,\n저자는 %s이며,\n가격은 %d원입니다.\n\n", book2.name, book2.auth, book2.price);

    return 0;
}