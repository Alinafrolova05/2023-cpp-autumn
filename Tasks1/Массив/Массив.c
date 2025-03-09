#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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

enum partOfArray {
    halfTheArray, 
    theWholeArray,
};

void rearrangementOfArrays(int m, int n, int* array, enum partOfArray arrayPart, int theMiddleOfArray, int start, int finish) {
    if (arrayPart == halfTheArray) {
        for (int i = 0; i < theMiddleOfArray; ++i) {
            swap(&array[i + start], &array[m - i - 1 + finish]);
        }
    }
    else {
        for (int i = 0; i != theMiddleOfArray; ++i) {
            swap(&array[i + start], &array[m - i - 1 + finish]);
        }
    }
}

void transpose(int m, int n, int* array) {
    rearrangementOfArrays(m, n, array, halfTheArray, m / 2, 0, 0);
    rearrangementOfArrays(m, n, array, halfTheArray, n / 2, m, n);
    rearrangementOfArrays(m, n, array, theWholeArray, (n + m) / 2, 0, n);
}

int main(void) {
    int m = 0;
    int n = 0;
    printf("Enter m - number of characters in the first part of the array: ");
    int result = scanf("%d", &m);
    if (result != 1 || !isPositive(m)) {
        printf("Input error!");
        return 0;
    }

    printf("Enter n - number of characters in the second part of the array: ");
    result = scanf("%d", &n);
    if (result != 1 || !isPositive(n)) {
        printf("Input error!");
        return 0;
    }

    int* array = (int*)calloc(m + n, sizeof(int));
    if (array == NULL) {
        printf("Error!!!");
        return -1;
    }
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
