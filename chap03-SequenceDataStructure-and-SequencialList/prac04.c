#include <stdio.h>

int n_big_number(int data[], int n);
int n_big_number_sort(int data[], int n);

int main()
{
    int data[10] = {1, 3, 5, 4, 7, 6, 12, 8, 9, 2};
    int n;
    scanf("%d", &n);
    printf("%d\n", n_big_number(data, n));
    return 0;
}

int n_big_number_sort(int data[], int n) {
    for (int i = 0; i < 10; i++) {
        int idx = i;
        for (int j = i + 1; j < 10; j++) {
            if (data[idx] > data[j]) {
                idx = j;
            }
        }
        int temp = data[i];
        data[i] = data[idx];
        data[idx] = temp;
    }
    return data[10 - n];
}

int n_big_number(int data[], int n) {
    int idx;
    for (int i = 0; i < n; i++) {
        idx = 0;
        for (int j = 0; j < 10; j++) {
            if (data[j] > data[idx]) {
                idx = j;
            }
        }
        if (i == n - 1) {
            continue;
        }
        data[idx] = 0;
    }
    return data[idx];
}