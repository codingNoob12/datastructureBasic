#include <stdio.h>
#include <string.h>

int main(void) {
    char str[20];

    printf("문자열을 입력하세요 : ");
    scanf("%s", str);

    printf("입력된 문자열은 \"%s\"입니다.\n", str);
    printf("입력된 문자열의 길이 = %d 입니다.\n", (int)strlen(str));

    return 0;
}