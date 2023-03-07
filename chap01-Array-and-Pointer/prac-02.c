#include <stdio.h>

int main(void) {
    int n;
    
    printf("\n1~9의 정수를 입력하세요 : ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 1; i <= 9; i++) {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    return 0;
}