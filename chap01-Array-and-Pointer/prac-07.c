#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[4][50];

    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
        gets(str[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
        for (int j = 0; j < strlen(str[i]); j++) {
            if (j == 0) {
                printf("%c", toupper(str[i][j]));
            }
            else if (str[i][j] != '-') {
                printf("%c", str[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}