#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testScanf(int result) { 
    return result == 1;
}
bool test(int size) {
    return size >= 0;
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

void selectionSort(int *array, int start, int finish) {
    for (int i = start; i < finish; ++i) {
        for (int j = i + 1; array[j] < array[j - 1] && j - 1 >= start; --j) {
            swap(&array[j], &array[j - 1]);
        }
    }
}
void sort(int* array, int start, int finish) {
    if (finish - start <= 5) {
        selectionSort(array, start, finish);
        return;
    }
    int value0 = array[start];
    int indexStart = start;
    int indexFinish = finish;
    while (indexStart + 1 <= indexFinish) {
        if (array[indexStart + 1] < value0) {
            swap(&array[indexStart + 1], &array[indexStart]);
            if (indexStart + 1 == indexFinish) {
                break;
            }
            indexStart++;
        } else if (array[indexStart + 1] >= value0) {
            if (indexStart + 1 == indexFinish) {
                break;
            }
            swap(&array[indexStart + 1], &array[indexFinish]);
            indexFinish--;
        }
    }
    sort(array, indexStart + 1, finish);
    sort(array, start, indexStart);
}

int main()
{
    int size = 0;
    printf("Enter size of the array: ");
    int result = scanf("%d", &size);
    if (!testScanf(result)) {
        printf("Input error!");
        return -1;
    }
    if (!test(size)) {
        printf("The number must be positive!");
        return -1;
    }

    int* array = (int*)calloc(size, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
    printf("The resulting array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    sort(array, 0, size - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    free(array);
	return 0;
}
