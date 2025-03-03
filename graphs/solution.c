#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Element {
    int vertex;
    int weight;
    struct Element* next;
} Element;

typedef struct Table {
    Element* element;
} Table;

void setNextElement(Element** element) {
    *element = (*element)->next;
}

void setToNextElement(Element** element, Element* anotherElement) {
    (*element)->next = anotherElement;
}

void setValueVertex(Element** element, int vertex) {
    (*element)->vertex = vertex;
}

void setValueWeight(Element** element, int weight) {
    (*element)->weight = weight;
}

Element* createElement(void) {
    return calloc(1, sizeof(Element));
}

Table* createTable(int size, bool* errorCode) {
    Table* segment = calloc(size, sizeof(Table));
    if (segment == NULL) {
        *errorCode = false;
        return NULL;
    }
    return segment;
}

Table* printFromFile(FILE* file, int* size, bool* errorCode) {
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
            if ((*current)->vertex == elementToDelete) {
                Element* toDelete = *current;
                *current = (*current)->next;
                free(toDelete);
            }
            else {
                current = &(*current)->next;
            }
        }
    }
}

void findMinElement(Element* stateElements, Table* table, int* minWeight, int* minVertex) {
    while (stateElements != NULL) {
        Element* current = table[stateElements->vertex - 1].element;
        if (current == NULL) {
            return;
        }
        while (current != NULL) {
            if (current->weight < *minWeight) {
                *minWeight = current->weight;
                *minVertex = current->vertex;
            }
            current = current->next;
        }
        stateElements = stateElements->next;
    }
}

void printTable(Table* states, int size) {
    for (int i = 0; i < size; ++i) {
        Element* current = states[i].element;
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

void deleteTable(Table** segment, int size) {
    for (int i = 0; i < size; ++i) {
        Element* current = (*segment)[i].element;
        while (current != NULL) {
            Element* toDelete = current;
            current = current->next;
            free(toDelete);
        }
    }
    free(*segment);
}

void solution(Table* table, Table* states, int size, int stateCount, bool* errorCode) {
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

Table* fillingOutTable(FILE* file, int* numberOfStates, bool* errorCode) {
    int size = 0;
    Table* table = printFromFile(file, &size, &errorCode);
    if (!errorCode) {
        return;
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
        return;
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

    solution(table, states, size, stateCount, errorCode);

    deleteTable(&table, size);
    return states;
}
