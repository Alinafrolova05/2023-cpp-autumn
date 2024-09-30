#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double testFaster(double clock1, double clock2) {
    return clock1 - clock2;
}

void swap(int* left, int* right) {
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void Bubblesort(int* array, int  size) {
    for (size_t i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size - 1; ++j) {
            if (array[j] > array[j + 1]) {
                count++;
                swap(&array[j], &array[j + 1]);
            }
        }
        if (count == 0) {
            break;
        }
    }
}

void Countsort(int* array, int *array2, int  size) {
    for (size_t i = 0; i < size; ++i) {
        array2[array[i]]++;
    }
    int i = 0;
    int move = 0;
    while (i < size) {
        for (size_t j = 0; j < array2[move]; ++j) {
            array[i] = move;
            i++;
        }
        move++;
    }
}

void Print(int* array, int  size) {
    printf("\n");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
}

int main(int argc, char argv[])
{
    const size = 100000;
    printf("The program compares Bubblesort and Countsort on an array of %d elements...", size);
    int* array = (int*)calloc(size, sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }

    int *array2 = (int *)calloc(size, sizeof(int));
    clock_t start1 = clock();
    Bubblesort(array, size);
    clock_t end1 = clock();
    double clockBubblesort = 1000.0 * (end1 - start1) / CLOCKS_PER_SEC;

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }

    clock_t start2 = clock();
    Countsort(array, array2, size);
    clock_t end2 = clock();
    double clockCountsort = 1000.0 * (end2 - start2) / CLOCKS_PER_SEC;
   
    printf("\n");

    if (testFaster(clockBubblesort, clockCountsort) < 0) {
        printf("Bubblesort is faster than Countsort.");
    } else if (testFaster(clockBubblesort, clockCountsort) == 0) {
        printf("Bubblesort is equal to Countsort.");
    } else {
        printf("Bubblesort is slower than Countsort.");
    }

    free(array);
    free(array2);
    return 0;
}
