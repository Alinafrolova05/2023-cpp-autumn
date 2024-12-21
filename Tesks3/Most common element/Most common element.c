#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int commonElement(int size, int *array, int max, int *pointerCountElement) {
    int* maxArray = (int*)calloc(max, sizeof(int));
    for (int i = 0; i < size; ++i) {
        maxArray[array[i]]++;
    }
    int countElement = 0;
    int mostCommonElement = 0;
    for (int i = 0; i < max; ++i) {
        if (maxArray[i] > countElement) {
            countElement = maxArray[i];
            mostCommonElement = i;
        }
    }
    *pointerCountElement = countElement;
    return mostCommonElement;
}

bool test(void) {
    int array1[] = { 3, 6, 68, 3, 0 };
    int array2[] = { 3, 6, 68, 88, 0 };
    int count = 0;
    commonElement(5, array2, 88, &count);
    return count <= 1 && commonElement(5, array1, 68, &count) == 3;
}

void printImplementation(int* array, int size, int max) {
    int countElement = 0;
    commonElement(size, array, max, &countElement);
    if (countElement <= 1) {
        printf("\nThere are no duplicate numbers in the array.");
    }
    else {
        printf("\nThe most common element is %d.", commonElement(size, array, max, &countElement));
    }
}

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    printf("Enter array size: ");
    int size = 0;
    
    int result = scanf("%d", &size);
    if (result != 1) {
        printf("Input error!");
        return -1;
    }

    srand(time(NULL));
    printf("Array of %d random numbers from 0 to 100:\n", size);
    int* array = (int*)calloc(size, sizeof(int));
    int max = 0;
    
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
        if (array[i] > max) {
            max = array[i];
        }
        printf("%d ", array[i]);
    }

    printImplementation(array, size, max);
   
    free(array);
	return 0;
}
