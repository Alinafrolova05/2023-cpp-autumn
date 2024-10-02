#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void swap(int * left, int* right) {
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

int main(void) {
    int a = 0;
    int b = 0;
    printf("Enter two numbers: \n");
    int result = scanf_s("%d", &a);
    result = scanf_s("%d", &b);
    swap(&a, &b);
    printf("\n%d, %d", a, b);
    return 0;
}