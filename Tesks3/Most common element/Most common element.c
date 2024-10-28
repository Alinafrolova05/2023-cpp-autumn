#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

bool testScanf(int result) {
    return result == 1;
} 
bool test(int size, int checkSize) {
    return size == checkSize && size > 0;
}
void commonElement(int size, int *array, int maxElement, int *pointerCountElement, int *pointerMostCountElement) {
    int* maxArray = (int*)calloc(maxElement, sizeof(int));
    for (int i = 0; i < size; ++i) {
        maxArray[array[i]]++;
    }
    int countElement = 0;
    int mostCommonElement = 0;
    for (int i = 0; i < maxElement; ++i) {
        if (maxArray[i] > countElement) {
            countElement = maxArray[i];
            mostCommonElement = i;
        }
    }
    *pointerCountElement = countElement;
    *pointerMostCountElement = mostCommonElement;
}

int main() {
    printf("Enter array size: ");
    int size = 10;
    int result = scanf("%d", &size);
    if (!testScanf(result)) {
        printf("Input error!");
        return -1;
    }
    int* array = (int*)calloc(size, sizeof(int));

    int maxElement = 0;
    srand(time(NULL));
    printf("Array of %d random numbers from 0 to 100:\n", size);

    int checkSize = 0;
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
        printf("%d ", array[i]);
        checkSize++;
    }
    if (!test(size, checkSize)) {
        printf("Size must be a natural positive number!");
        return -1;
    }
    
    int countElement = 0;
    int mostCommonElement = 0;

    commonElement(size, array, maxElement, &countElement, &mostCommonElement);

    
    if (countElement <= 1) {
        printf("\nThere are no duplicate numbers in the array.");
    } else {
        printf("\nThe most common element is %d.", mostCommonElement);
    }
    
    free(array);
	return 0;
}
