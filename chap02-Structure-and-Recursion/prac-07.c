#include <stdio.h>

int sumOf1toN(int n) {
    if (n <= 1) {
        return 1;
    }

    return n + sumOf1toN(n - 1);
}

int main(void) {
    int n;
    scanf("%d", &n);

    printf("1부터 %d까지의 합은 %d입니다.\n", n, sumOf1toN(n));
    
    return 0;
}