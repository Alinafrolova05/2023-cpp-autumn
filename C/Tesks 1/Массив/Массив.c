#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool testScanf(int result) {
    return result == 1;
}
bool testPositive(int m) {
    return m >= 0;
}
bool testSwap(int* left, int* right) {
    return left != right;
}

void swap(int* left, int* right) {
    if (!testSwap(left, right)) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void cycle(int m, int n, int* array, int sign, int condition1, int condition2, int condition3) {
    if (sign == 1) {
        for (int i = 0; i < condition1; ++i) {
            swap(&array[i + condition2], &array[m - i - 1 + condition3]);
        }
    }
    else {
        for (int i = 0; i != condition1; ++i) {
            swap(&array[i + condition2], &array[m - i - 1 + condition3]);
        }
    }
}

void transpose(int m, int n, int* array) {
    cycle(m, n, array, 1, m / 2, 0, 0);
    cycle(m, n, array, 1, n / 2, m, n);
    cycle(m, n, array, 0, (n + m) / 2, 0, n);
}

int main() {
    int m = 1;
    int n = 1;
    printf("Enter m - number of characters in the first part of the array: ");
    int result = scanf("%d", &m);
    if (!testScanf(result) || !testPositive(m)) {
        printf("Input error!");
        return 0;
    }

    printf("Enter n - number of characters in the second part of the array: ");
    result = scanf("%d", &n);
    if (!testScanf(result) || !testPositive(n)) {
        printf("Input error!");
        return 0;
    }

    int* array = (int*)calloc(m + n, sizeof(int));
    printf("Enter m numbers for the first part of the array: ");
    printf("\n");
    for (int i = 0; i < m; ++i) {
        result = scanf("%d", &array[i]);
    }

    printf("Enter n numbers for the second part of the array: ");
    printf("\n");
    for (int i = 0; i < n; ++i) {
        result = scanf("%d", &array[i + m]);
    }

    transpose(m, n, array);
    printf("\n");
    for (int i = 0; i < n + m; ++i) {
        printf(" %d ", array[i]);
    }

    free(array);
    return 0;
}