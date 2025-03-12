#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum PartOfArray {
    HalfTheArray,
    TheWholeArray,
};

bool isPositive(int m) {
    return m >= 0;
}

void swap(int* left, int* right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void reverseArray(int* array, int start, int finish) {
    for (int i = 0; i < (finish - start + 1) / 2; ++i) {
        swap(&array[start + i], &array[finish - i]);
    }
}

void transpose(int m, int n, int* array) {
    reverseArray(array, 0, m - 1);
    reverseArray(array, m, m + n - 1);
    reverseArray(array, 0, m + n - 1);
}

int main(void) {
    int m = 0;
    int n = 0;

    printf("Enter m - number of elements in the first part of the array: ");
    if (scanf("%d", &m) != 1 || !isPositive(m)) {
        printf("Input error!");
        return -1;
    }

    printf("Enter n - number of elements in the second part of the array: ");
    if (scanf("%d", &n) != 1 || !isPositive(n)) {
        printf("Input error!");
        return -1;
    }

    int* array = (int*)calloc(m + n, sizeof(int));
    if (array == NULL) {
        printf("Error allocating memory!");
        return -1;
    }

    printf("Enter %d numbers for the first part of the array:\n", m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &array[i]);
    }

    printf("Enter %d numbers for the second part of the array:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i + m]);
    }

    transpose(m, n, array);

    printf("\nResulting array:\n");
    for (int i = 0; i < m + n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
