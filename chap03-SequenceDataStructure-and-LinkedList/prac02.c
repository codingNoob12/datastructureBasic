#include <stdio.h>

int main()
{
    int i, *ptr;
    int scale[2][2][4] = { 
        {
            {63, 84, 140, 130},
            {157, 209, 251, 312}
        },
        {
            {59, 80, 130, 135},
            {149, 187, 239, 310}
        } };
    ptr = scale;

    for (i = 0; i < 16; i++) {
        printf("\n address : %u   scale %d = %d", ptr, i, *ptr);
    }
    printf("\n");

    return 0;
}