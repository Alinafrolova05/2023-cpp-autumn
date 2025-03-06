#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "hash.h"
#include "test.h"
#include "table.h"

void printSolution(char* array[], int arraySize, bool* errorCode, int** task) {
    int sizeOfTable = printTable(array, arraySize, errorCode, task);
    printf("\ndutyCycle: %d/%d\n", (*task)[0], sizeOfTable);
    printf("averageListLength: %d/%d\n", (*task)[1], arraySize);
    printf("maxLength: %d", (*task)[2]);
}

void task(void) {
    bool errorCode = true;

    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error!");
        return;
    }

    char* array[256] = { 0 };
    int i = 0;

    char buffer[100] = "";
    while (fscanf(file, "%99s", buffer) == 1 && i < 256) {
        array[i] = malloc(strlen(buffer) + 1);
        if (array[i] == NULL) {
            printf("Error!");
            errorCode = false;
            free(task);

            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            return;
        }
        strcpy(array[i], buffer);
        i++;
    }
    fclose(file);

    float* task = NULL;
    printSolution(array, i, &errorCode, &task);
    free(task);

    for (int j = 0; j < i; j++) {
        free(array[j]);
    }
}

int main(void) {
    if (!test()) {
        fprintf(stderr, "Error!!!\n");
        return -1;
    }
    task();
    return 0;
}
