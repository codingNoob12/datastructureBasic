#include <stdio.h>

int main()
{
    int arr[3][3] = {
        {1, 10, 14},
        {20, 3, 5},
        {15, 12, 0}
    };

    for (int i = 0; i < 3; i++) {
        int row_sum = 0, col_sum = 0;
        for (int j = 0; j < 3; j++) {
            row_sum += arr[i][j];
            col_sum += arr[j][i];
        }
        printf("%d행의 합 : %d\n", i + 1, row_sum);
        printf("%d열의 합 : %d\n", i + 1, col_sum);
    }

    return 0;
}