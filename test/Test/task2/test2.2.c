#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    int size = 10;
    int* array = (int*)calloc(100, sizeof(int));
    if (array == NULL) {
        printf("Error.\n");
        return 1;
    }

    int start = 0;
    int finish = 0;

    for (int i = 0; i < 6; ++i) {
        enqueue(array, &finish, i);
    }

    printf("Array: ");
    print(array, start, finish);

    for (int i = 6; i < 50; ++i) {
        enqueue(array, &finish, i);
        dequeue(array, &start, &finish);
    }

    printf("Array: ");
    print(array, start, finish);

    free(array);
    return 0;
}
