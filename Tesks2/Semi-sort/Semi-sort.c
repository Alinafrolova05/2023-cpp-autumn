#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testScanf(int result) {
    return result == 1;
}

void swap(int *left,int *right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void sort(int *array, int size) {
    int value0 = array[0];
    int indexArray = 0;
    int indexFinish = size - 1; 

    while (indexArray + 1 <= indexFinish) {
        if (array[indexArray + 1] < value0) {
            swap(&array[indexArray + 1], &array[indexArray]);
            indexArray++;
        } else if (array[indexArray + 1] >= value0) {
            if (indexArray + 1 == indexFinish) {
                break;
            }
            swap(&array[indexArray + 1], &array[indexFinish]);
            indexFinish--;
        }
    }
}

int main() {
    int size = 0;
    printf("Specify the number of elements in the array: ");
    int result = scanf("%d", &size);
    if (!testScanf(result) || size < 0) {
        printf("Input error!");
        return 0;
    }
    int* array = (int*)calloc(size, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
    printf("Original array: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    sort(array, size);

    printf("\nThe resulting array: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
