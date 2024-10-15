#include "Module.h"
#include <stdlib.h>
void commonElement(int size, int* array, int maxElement, int* pointerCountElement, int* pointerMostCountElement) {
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
