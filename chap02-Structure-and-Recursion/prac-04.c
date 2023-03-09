#include <stdio.h>

int fact(int n) {
    printf("fact(%d) 함수 호출!\n", n);

    if (n <= 1) {
        printf("fact(%d) 값 %d 반환\n", n, 1);
        return n;
    }

    int res = n * fact(n - 1);
    printf("fact(%d) 값 %d 반환\n", n, res);
    return res;
}

int main(void) {
    int n;
    printf("정수를 입력하세요 : ");
    scanf("%d", &n);

    printf("%d의 팩토리얼 값은 %d입니다.\n", n, fact(n));

    return 0;
}