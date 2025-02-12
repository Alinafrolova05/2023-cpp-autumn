#define _CRT_SECURE_NO_WARNINGS
#define HASH_TABLE 100

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "table.h"
#include "hash.h"
#include "list.h"

int getSizeOfTable(void) {
    return HASH_TABLE;
}

typedef struct Segment {
    Element* table;
} Segment;

Segment* createHasnTable(bool* errorCode) {
    Segment* segment = calloc(HASH_TABLE, sizeof(Segment));
    if (segment == NULL) {
        *errorCode = false;
        return NULL;
    }
    return segment;
}

Element* search(Segment* segment, const char* key) {
    int index = getValueHash(key);
    return searchValueOfElement(segment[index].table, key);
}

void insert(Segment* segment, const char* key, bool* errorCode) {
    Element* found = search(segment, key);
    if (found) {
        intcrValueCount(&found);
        return;
    }
    int index = getValueHash(key);
    push(&(segment[index].table), key, errorCode);
}

void freeSegments(Segment* segment) {
    for (int i = 0; i < HASH_TABLE; ++i) {
        Element* current = segment[i].table;
        pop(&current);
    }
    free(segment);
}

void printTable(Segment* segment) {
    for (int i = 0; i < HASH_TABLE; ++i) {
        printElements(segment[i].table);
    }
}

float* calculate(Segment* segment, int arraySize) {
    float* task = malloc(3 * sizeof(float));
    task[0] = (float)arraySize / HASH_TABLE;

    int length = 0;
    int max = 0;
    for (int i = 0; i < HASH_TABLE; ++i) {
        Element* current = segment[i].table;
        int len = 0;
        while (current != NULL) {
            len++;
            setNextElement(&current);
        }
        length += len;
        if (len > max) {
            max = len;
        }
    }

    if (arraySize > 0) {
        task[1] = (float)length / arraySize;
    }
    task[2] = (float)max;
    return task;
}

Segment* fillOutTheTable(const char* array[], int arraySize, bool* errorCode, float** task) {
    Segment* segment = createHasnTable(errorCode);
    if (!*errorCode) {
        return NULL;
    }
    for (int i = 0; i < arraySize; ++i) {
        insert(segment, array[i], errorCode);
        if (!*errorCode) {
            freeSegments(segment);
            return NULL;
        }

        if (!search(segment, array[i])) {
            *errorCode = false;
            freeSegments(segment);
            return NULL;
        }
    }
    *task = calculate(segment, arraySize);
    return segment;
}

void solution(char* array[], int arraySize, bool* errorCode, float** task) {
    freeSegments(fillOutTheTable(array, arraySize, errorCode, task));
}

void printSolution(char* array[], int arraySize, bool* errorCode, float** task) {
    Segment* segment = fillOutTheTable(array, arraySize, errorCode, task);
    printTable(segment);
    printf("\ndutyCycle: %.2f\n", (*task)[0]);
    printf("averageListLength: %.2f\n", (*task)[1]);
    printf("maxLength: %.0f", (*task)[2]);
    freeSegments(segment);
}
