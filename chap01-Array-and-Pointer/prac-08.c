#include <stdio.h>
#include <string.h>

int main(void) {
    char string1[] = "I Love C programing!";
    char string2[30];
    char* ptr1 = string1;
    char* ptr2;

    printf("string1의 주소 = %d, ptr1 = %d\n", (int)string1, (int)ptr1);
    printf("string1 = %s\n", string1);
    printf("ptr1 = %s\n", ptr1);

    ptr2 = string1 + 7;
    printf("\n%s\n", (string1 + 7));
    printf("%s\n\n", ptr2);

    for (int i = strlen(string1) - 1; i >= 0; i--) {
        printf("%c", *(string1 + i));
    }

    strcpy(string2, string1);
    printf("\nstring1 = %s\n", string1);
    printf("string2 = %s\n", string2);

    printf("\nstring1 = %s\n", string1);

    return 0;
}