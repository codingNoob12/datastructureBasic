#include <stdio.h>

int main()
{
    int arr1[][2] = {
        {1, 2},
        {3, 4}
    };
    int arr2[][2] = {
        {5, 6},
        {7, 8}
    };
    int arr3[][2] = {{0}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d\t", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}