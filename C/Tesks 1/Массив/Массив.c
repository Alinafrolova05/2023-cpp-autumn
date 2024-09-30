#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* left, int* right) {

    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void Transposition(int m, int n, int*mas) {
    for (int i = 0; i < m / 2; ++i) {
        swap(&mas[i], &mas[(m - i - 1)]);
    }
    for (int i = 0; i < n / 2; ++i) {
        swap(&mas[i + m], &mas[n + m - i - 1]);
    }
    for (int i = 0; i != (n + m) / 2; ++i) {
        swap(&mas[i], &mas[n + m - i - 1]);
    }
    printf("\n");
    for (int i = 0; i < n + m; ++i) {
        printf(" %d ", mas[i]);
    }
}

int main() {
    int m = 0;
    int n = 0;
    printf("Enter m - number of characters in the first part of the array: ");
    int result = scanf("%d", &m);
    printf("Enter n - number of characters in the second part of the array: ");
    result = scanf("%d", &n);
    int* mas = (int*)calloc(m + n, sizeof(int));

    printf("Enter m numbers for the first part of the array: ");
    printf("\n");
    for (int i = 0; i < m; ++i) {
        result = scanf("%d", &mas[i]);
    }

    printf("Enter n numbers for the second part of the array: ");
    printf("\n");
    for (int i = 0; i < n; ++i) {
        result = scanf("%d", &mas[i + m]);
    }

    Transposition(m, n, mas);

    free(mas);
    return 0;
}
