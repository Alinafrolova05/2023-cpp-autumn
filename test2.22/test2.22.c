#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void selectionSort(int size, int array[]) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(&array[i], &array[minIndex]);
    }
}

bool test(void) {
    int array[10] = { 2, 7, 4, 56, 3 };
    int checkArray[10] = { 2, 3, 4, 7, 56 };
    int size = 5;
    selectionSort(size, array);
    for (int i = 0; i < size; ++i) {
        if (array[i] != checkArray[i]) {
            return false;
        }
    }
    return true;
}

void program(void) {
    int array[10] = { 0 };
    printf("Enter 10 elements in the array: ");
    for (int i = 0; i < 10; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Error!\n");
            return;
        }
    }
    selectionSort(10, array);
    printf("Resulting array: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }
}

int main(void) {
    
    if (!test()) {
        printf("Error!");
        return -1;
    }

    program();
    
    return 0;
}
