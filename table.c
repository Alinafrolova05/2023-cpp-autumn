#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "table.h"
#include "list.h"

typedef struct HashTable {
    Element* table;
} HashTable;

HashTable* createHashTable(int sizeOfTable, bool* errorCode) {
    HashTable* segment = calloc(sizeOfTable, sizeof(HashTable));
    if (segment == NULL) {
        *errorCode = false;
        return NULL;
    }
    return segment;
}

void toChangeHashTableSize(HashTable** table, int sizeOfTable, bool* errorCode) {
    HashTable* newTable = (HashTable*)realloc(*table, sizeOfTable * sizeof(HashTable));
    if (newTable == NULL) {
        *errorCode = false;
        return;
    }
    for (int i = 0; i < sizeOfTable; ++i) {
        newTable[i].table = NULL;
    }
    *table = newTable;
}

void freeTable(HashTable* hashTable, int sizeOfTable) {
    for (int i = 0; i < sizeOfTable; ++i) {
        Element* current = hashTable[i].table;
        pop(&(current));
    }
    free(hashTable);
}

int hash(const char* key, int sizeOfTable) {
    int hashIndex = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        int number = (int)key[i];
        if (key[i] == 'g' || key[i] == 'j' || key[i] == 'p' || key[i] == 'q' || key[i] == 'y') {
            number *= 23;
        }
        if (i % 2 == 0) {
            number /= 3;
        }
        if (i % 3 == 0) {
            number %= 11;
        }
        hashIndex += number;
    }
    return hashIndex % sizeOfTable;
}

Element* search(HashTable* segment, int sizeOfTable, const char* key) {
    int size = sizeOfTable;
    while (size > 1) {
        int index = hash(key, size);
        Element* found = searchByValueOfElement(segment[index].table, key);
        if (found) {
            return found;
        }
        size /= 2;
    }    
    return NULL;
}

void insert(HashTable* segment, int sizeOfTable, const char* key, bool* errorCode) {
    Element* found = search(segment, sizeOfTable, key);
    if (found) {
        incrementValueCount(found);
        return;
    }
    int index = hash(key, sizeOfTable);
    push(&(segment[index].table), key, errorCode);
}

CountTask* calculate(HashTable* segment, int sizeOfTable, int arraySize, bool* errorCode) {
    CountTask* task = createCountTask();
    if (task == NULL) {
        *errorCode = false;
        return;
    }
    setArraySize(task, arraySize);

    int length = 0;
    int max = 0;
    for (int i = 0; i < sizeOfTable; ++i) {
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
        setAverageListLength(task, length);
    }
    setMaxListLength(task, max);
    return task;
}

HashTable* fillOutTheTable(const char* array[], int* sizeOfTable, int arraySize, bool* errorCode, CountTask** task) {
    HashTable* segment = createHashTable(*sizeOfTable, errorCode);
    if (!*errorCode) {
        return NULL;
    }
    int countInserts = 0;
    for (int i = 0; i < arraySize; ++i) {
        insert(segment, *sizeOfTable, array[i], errorCode);
        if (!*errorCode) {
            freeTable(segment, *sizeOfTable);
            return NULL;
        }
        countInserts++;

        if (!search(segment, *sizeOfTable, array[i])) {
            *errorCode = false;
            freeTable(segment, *sizeOfTable);
            return NULL;
        }

        if (countInserts * 2 > *sizeOfTable) {
            *sizeOfTable *= 2;
            toChangeHashTableSize(&segment, *sizeOfTable, errorCode);
            if (!*errorCode) {
                freeTable(segment, *sizeOfTable);
                return NULL;
            }
        }
    }
    *task = calculate(segment, *sizeOfTable, arraySize, errorCode);
    if (!*errorCode) {
        freeTable(segment, *sizeOfTable);
        return NULL;
    }
    return segment;
}

int printTable(const char* array[], int arraySize, bool* errorCode, CountTask** task) {
    int sizeofTable = 100;
    HashTable* hashTable = fillOutTheTable(array, &sizeofTable, arraySize, errorCode, task);
    for (int i = 0; i < sizeofTable; ++i) {
        printElements(hashTable[i].table);
    }
    freeTable(hashTable, sizeofTable);
    return sizeofTable;
}

void solution(const char* array[], int arraySize, bool* errorCode, CountTask** task) {
    int sizeofTable = 100;
    HashTable* hashTable = fillOutTheTable(array, &sizeofTable, arraySize, errorCode, task);
    freeTable(hashTable, sizeofTable);
}
