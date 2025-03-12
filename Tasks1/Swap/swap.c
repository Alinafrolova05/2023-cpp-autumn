#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int* left, int* right) {
    *left = *left + *right;
    *right = *left - *right;
    *left = *left - *right;
}

int main(void) {
    int a = 1;
    int b = 2;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
