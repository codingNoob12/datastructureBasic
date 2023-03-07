#include <stdio.h>

int main(void) {
    int scores[] = {91, 86, 74};
    char grades[] = {'A', 'B', 'C'};

    printf(" *** 학년별 취득 학점 *** \n\n");
    for (int i = 0; i < 3; i++) {
        printf("%d학년 : 총점 = %d 등급 = %c\n", i + 1, scores[i], grades[i]);
    }

    return 0;
}