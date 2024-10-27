#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

int main(void) {
    int a = 1;
    swap(&a, &a);
    printf("%d", a);
    return 0;
}