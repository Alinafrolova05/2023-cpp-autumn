#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void recursion(int* array1, int* array2) {
    if (sizeof(array1) < 1 || sizeof(array2) < 1) {
        return;
    }
    //int* addArray = 
    recurtion(array1, array2);
    recurtion(array1, array2);
    int test = 0;
    int* newArray = (int*)malloc(sizeof(int));
    int pointer1 = 0;
    int pointer2 = 0;
    int i = 0;
    while (1) {
        if (i == sizeof(array1)) {
            test = 1;
            break;
        }
        if (i == sizeof(array2)) {
            test = 2;
            break;
        }
        if (array1[pointer1] < array2[pointer2] || array1[pointer1] == array2[pointer2]) {
            newArray[i] = array1[pointer1];
        }
        if (array1[pointer1] > array2[pointer2]) {
            newArray[i] = array2[pointer2];
        }
    }
    if (test == 1) {
        while (i < sizeof(array2)) {
            newArray[i] = array2[pointer2];
        }
    }
    if (test == 2) {
        while (i < sizeof(array1)) {
            newArray[i] = array1[pointer1];
        }
    }
    free(array1);
    free(array2);
}

int main() {
    FILE* file = fopen("text.txt", "w+");
    int size = 10;
    printf("Enter less than 100 characters: ");
    int array[100] = { 0 };
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result = scanf("%d", array[i]);
    }

    printf("Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf(" %d", array[i]);
    }

    fclose(file);
    return 0;
}
