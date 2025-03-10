#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int main(void) {
    int a = 1;
    int b = 2;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
