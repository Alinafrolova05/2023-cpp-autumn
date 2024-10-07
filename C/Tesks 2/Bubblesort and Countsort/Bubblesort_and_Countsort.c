#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double testFaster(double clock1, double clock2) {
    return clock1 - clock2;
}

bool testSwap(int* left, int* right) {
    return left != right; 
}
void swap(int *left, int *right) {
    if (!testSwap(left, right)) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void bubbleSort(int *array, int  size) {
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
bool testBubbleSort(int *array) {
    bubbleSort(array, 5);
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (array[i] <= array[i + 1]) {
            count++;
        }
    }
    return count == 4;
}

void countSort(int *array, int  size) {
    int* array2 = (int*)calloc(size, sizeof(int));
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
    free(array2);
}
bool testCountSort(int *array) {
    countSort(array, 5);
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (array[i] <= array[i + 1]) {
            count++;
        }
    }
    return count == 4;
}

void Print(int *array, int size) {
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
    if (!testBubbleSort(array)) {
        printf("Error! Bubble sort doesn't work!");
        return 0;
    }
    if (!testCountSort(array)) {
        printf("Error! Counting sort doesn't work!");
        return 0;
    }

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }

    
    clock_t start1 = clock();
    bubbleSort(array, size);
    clock_t end1 = clock();
    double clockBubblesort = 1000.0 * (end1 - start1) / CLOCKS_PER_SEC;

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }

    clock_t start2 = clock();
    countSort(array, size);
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
    return 0;
}
