#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Table {
    Element* element;
} Table;

Table* createTable(int size, bool* errorCode) {
    Table* segment = calloc(size, sizeof(Table));
    if (segment == NULL) {
        *errorCode = false;
        return NULL;
    }
    return segment;
}

Table* loadFromFile(FILE* file, int* size, bool* errorCode) {
    fseek(file, 0, SEEK_SET);
    int edges = 0;
    fscanf(file, "%d %d", size, &edges);
    Table* table = createTable(*size, errorCode);
    if (!*errorCode) return NULL;

    int vertex1 = 0;
    int vertex2 = 0;
    int len = 0;
    while (fscanf(file, "%d %d %d", &vertex1, &vertex2, &len) == 3) {
        push(&table[vertex1 - 1].element, vertex2, len, errorCode);
        push(&table[vertex2 - 1].element, vertex1, len, errorCode);

        if (!*errorCode) {
            free(table);
            return NULL;
        }
    }
    return table;
}

void deleteElementInTable(Table** table, int size, int elementToDelete) {
    for (int j = 0; j < size; ++j) {
        if (j == elementToDelete) {
            continue;
        }
        Element** current = &(*table)[j].element;
        while (*current != NULL) {
            if (getElementVertex(*current) == elementToDelete) {
                Element* toDelete = *current;
                moveToNext(current);
                free(toDelete);
            }
            else {
                moveToNext(current);
            }
        }
    }
}

void findMinElement(Element* stateElements, Table* table, int* minWeight, int* minVertex) {
    while (stateElements != NULL) {
        Element* current = table[getElementVertex(stateElements) - 1].element;
        if (current == NULL) {
            return;
        }
        while (current != NULL) {
            if (getElementWeight(current) < *minWeight) {
                *minWeight = getElementWeight(current);
                *minVertex = getElementVertex(current);
            }
            moveToNext(&current);
        }
        moveToNext(&stateElements);

    }
}

void printTable(Table* states, int size) {
    for (int i = 0; i < size; ++i) {
        Element* current = states[i].element;
        while (current != NULL) {
            printf("%d ", getElementVertex(current));
            moveToNext(&current);
        }
        printf("\n");
    }
}

void deleteTable(Table** segment, int size) {
    for (int i = 0; i < size; ++i) {
        Element* current = (*segment)[i].element;
        while (current != NULL) {
            Element* toDelete = current;
            moveToNext(&current);
            free(toDelete);
        }
    }
    free(*segment);
}
void solve(Table* table, Table* states, int size, int stateCount, bool* errorCode) {
    if (table == NULL || states == NULL) return;
    int count = size - stateCount;
    int check = 0;
    for (int i = 0; count > 0; ++i) {
        int minVertex = 0;
        int minWeight = INT_MAX;
        findMinElement(states[i % stateCount].element, table, &minWeight, &minVertex);
        if (minWeight == INT_MAX) {
            check++;
            if (check > size) {
                break;
            }
            continue;
        }
        push(&states[i % stateCount].element, minVertex, minWeight, errorCode);
        count--;

        if (!*errorCode) {
            deleteTable(&states, stateCount);
            deleteTable(&table, size);
            return;
        }

        deleteElementInTable(&table, size, minVertex);
    }
}

Table* fillOutTable(FILE* file, int* numberOfStates, bool* errorCode) {
    int size = 0;
    Table* table = loadFromFile(file, &size, errorCode);
    if (!errorCode) {
        return NULL;
    }

    char buffer[256] = { 0 };
    fgets(buffer, 256, file);

    Table* states = NULL;
    int stateCount = 0;

    if (fscanf(file, "%d", &stateCount) == 1) {
        states = createTable(stateCount, errorCode);
    }
    else {
        *errorCode = false;
        deleteTable(&table, size);
        return NULL;
    }
    *numberOfStates = stateCount;

    int number = 0;
    for (int i = 0; fscanf(file, "%d", &number) == 1; ++i) {
        if (i > stateCount) {
            break;
        }
        deleteElementInTable(&table, size, number);
        push(&states[i].element, number, 0, errorCode);
    }

    solve(table, states, size, stateCount, errorCode);

    deleteTable(&table, size);
    return states;
}
