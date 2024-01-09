#include <stdio.h>

int main(void) {
    int n;
    
    while (1) {
        printf("1~9의 정수를 입력하세요 : ");
        scanf("%d", &n);
        if (n >= 1 && n <= 9) {
            printf("\n");
            break;
        }
    }

    for (int i = 1; i <= 9; i++) {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    return 0;
}