#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double testFaster(double clock1, double clock2) {
    return clock1 - clock2;
}

void swap(int *left, int *right) {
    if (left == right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void bubbleSort(int *array, int size) {
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

bool testBubbleSort() {
    int array[] = { 9, 2, 7, 1, 8 };
    bubbleSort(array, 5);
    for (int i = 0; i < 4; ++i) {
        if (array[i] >= array[i + 1]) {
            return false;
        }
    }
    return true;
}

void countSort(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int* arrayMax = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < size; ++i) {
        arrayMax[array[i]]++;
    }

    int i = 0;
    for (int j = 0; j <= max; j++) {
        while (arrayMax[j] > 0) {
            array[i++] = j;
            arrayMax[j]--;
        }
    }

    free(arrayMax);
}

bool testCountSort() {
    int array[] = { 9, 2, 7, 1, 8 };
    countSort(array, 5);
    for (int i = 0; i < 4; ++i) {
        if (array[i] >= array[i + 1]) {
            return false;
        }
    }
    return true;
}

void initialization(int array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }
}

void countTimeOfBubbleSort(int* array, int size, double* pointer) {
    clock_t start = clock();
    bubbleSort(array, size);
    clock_t end = clock();
    double clockBubblesort = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    *pointer = clockBubblesort;
}

void countTimeOfCountSort(int* array, int size, double* pointer) {
    clock_t start = clock();
    countSort(array, size);
    clock_t end = clock();
    double clockCountsort = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    *pointer = clockCountsort;
}

void printResultOfCounting(double clockBubblesort, double clockCountsort) {
    if (testFaster(clockBubblesort, clockCountsort) < 0) {
        printf("Bubblesort is faster than Countsort.");
    }
    else if (testFaster(clockBubblesort, clockCountsort) == 0) {
        printf("Bubblesort is equal to Countsort.");
    }
    else {
        printf("Bubblesort is slower than Countsort.");
    }
}

int main(int argc, char argv[])
{
    if (!testBubbleSort()) {
        printf("Error! Bubble sort doesn't work!");
        return -1;
    }
    if (!testCountSort()) {
        printf("Error! Counting sort doesn't work!");
        return -1;
    }

    const size = 100000;
    printf("The program compares Bubblesort and Countsort on an array of %d elements...", size);
    int* array = (int*)calloc(size, sizeof(int));
    initialization(array, size);

    double clockBubblesort = 0;
    double clockCountsort = 0;

    countTimeOfBubbleSort(array, size, &clockBubblesort);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }
    countTimeOfCountSort(array, size, &clockCountsort);

    printf("\n");
    printResultOfCounting(clockBubblesort, clockCountsort);

    free(array);
    return 0;
}
