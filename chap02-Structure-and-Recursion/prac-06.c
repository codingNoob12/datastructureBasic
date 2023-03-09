#include <stdio.h>

void multiplyTable(int table, int mul) {
    if (mul < 1) {
        return;
    }

    multiplyTable(table, mul - 1);

    printf("%d x %d = %d 입니다.\n", table, mul, table * mul);
}

int main(void) {
    int table;
    printf("몇단을 만드시겠습니까? : ");
    scanf("%d", &table);

    multiplyTable(table, 9);

    return 0;
}