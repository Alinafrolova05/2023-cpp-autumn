#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testSize(float size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        count++;
    }
    return size == count && size >= 0;
} 
bool testSwap(int* left, int* right) {
    return left != right;
}
bool testScanf(int result) {
    return result == 1;
}
void swap(int *left,int *right) {
    if (!testSwap(left, right)) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void sort(int *array, int size) {
    int value0 = array[0];
    int indexarray0 = 0;
    int indexfinish = size - 1;
    while (indexarray0 + 1 <= indexfinish) {
        if (array[indexarray0 + 1] < value0) {

            swap(&array[indexarray0 + 1], &array[indexarray0]);
            indexarray0++;
        } else if (array[indexarray0 + 1] >= value0) {
            if (indexarray0 + 1 == indexfinish) {
                break;
            }
            swap(&array[indexarray0 + 1], &array[indexfinish]);
            indexfinish--;
        }
    }
}

int main()
{
    float size = 0;
    printf("Specify the number of elements in the array: ");
    int result = scanf("%f", &size);
    if (!testScanf(result)) {
        printf("Input error!");
        return 0;
    }
    if (!testSize(size)) {
        printf("Error! Array size must be a positive natural number!");
        return 0;
    }
    int* array = (int*)calloc(size, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
    printf("Primordial Array: \n");
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