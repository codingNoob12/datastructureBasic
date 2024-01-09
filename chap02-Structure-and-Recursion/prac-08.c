#include <stdio.h>

void recursion(int n) {
    if (n < 1) {
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");

    recursion(n - 1);
}

int main(void) {
    int n;
    printf("별산의 높이를 입력하여주세요! : ");
    scanf("%d", &n);

    recursion(n);

    return 0;
}