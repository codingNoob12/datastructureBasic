#include <stdio.h>

int main(void) {
    char students[2][3][50];
    char mes[3][20] = {"이름", "학과", "학번"};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("학생 %d의 %s : ", i + 1, mes[j]);
            gets(students[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 2; i++) {
        printf("학생 %d\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("\t%s\n", students[i][j]);
        }
        printf("\n");
    }

    return 0;
}