#include <stdio.h>

int main()
{
    int i, *ptr;
    int scale[2][4] = {
        {63, 84, 140, 130},
        {157, 209, 251, 312} };
    ptr = scale;

    for (i = 0; i < 8; i++, ptr++) {
        printf("\n address : %u scale %d = %d", ptr, i, *ptr);
    }
    printf("\n");

    return 0;
}