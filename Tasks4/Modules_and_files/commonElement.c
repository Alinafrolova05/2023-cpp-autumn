#include "commonElement.h"
#include <stdio.h>
#include <stdlib.h>

int commonElement(int size, int* array, int max, int* pointerCountElement) {
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