#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isPositive(float value) {
    return value > 0;
}

void swap(int* left, int* right) {
    if (left== right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

bool binarySearch(int* array, int size, int k) {
    sort(array, size);
    int left = 0, right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (array[middle] == k) {
            return true;
        }
        if (array[middle] < k) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return false;
}

bool test(void) {
    int array[] = { 2, 67, 45, 8, 3, 90 };
    return binarySearch(array, 6, 3) == true && binarySearch(array, 6, 46) == false;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf(" %d", array[i]);
    }
}

void printSearch(int* array, int size, int* kArray, int kSize) {
    int countIdenticalNumbers = 0;
    for (int i = 0; i < kSize; ++i) {
        if (binarySearch(array, size, kArray[i])) {
            countIdenticalNumbers++;
            printf("%d ", kArray[i]);
        }
    }
    if (countIdenticalNumbers == 0) {
        printf("No number belongs to the first array.");
    }
}

int main(void) {
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    int size = 0;
    printf("Enter size of the array: ");
    int result = scanf("%d", &size);
    if (result != 1 || !isPositive(size)) {
        printf("Input error! The number must be a positive integer.\n");
        return -1;
    }

    int kSize = 0;
    printf("Enter the number of numbers to check: ");
    result = scanf("%d", &kSize);
    if (result != 1 || !isPositive(kSize)) {
        printf("Input error! The number must be a positive integer.\n");
        return -1;
    }

    int* array = (int*)calloc(size, sizeof(int));
    int* kArray = (int*)calloc(kSize, sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
    for (int i = 0; i < kSize; ++i) {
        kArray[i] = rand() % 100;
    }

    printf("The resulting array: ");
    printArray(array, size);

    printf("\nChecked numbers: ");
    printArray(kArray, kSize);

    printf("\nNumbers that are in the first array: ");
    
    printSearch(array, size, kArray, kSize);

    free(array);
    free(kArray);
    return 0;
}
