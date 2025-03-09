#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int main(void)
{
    int a = 1;
    swap(&a, &a);
    printf("%d", a);
    return 0;
}
