#define _CRT_SECURE_NO_WARNINGS
#define HASH_TABLE_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "table.h"

int getSizeOfTable(void) {
    return HASH_TABLE_SIZE;
}

typedef struct HashTable {
    Element* table;
} HashTable;

Element* getElement(HashTable* hashTable, int i) {
    return hashTable[i].table;
}

HashTable* createHashTable(int sizeOfTable, bool* errorCode) {
    HashTable* segment = calloc(sizeOfTable, sizeof(HashTable));
    if (segment == NULL) {
        *errorCode = false;
        return NULL;
    }
    return segment;
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

Element* searchByValueOfElement2(HashTable* hashTable, int sizeOfTable, char* value) {
    
    for (int i = 0; i < sizeOfTable; ++i) {
        //printf(" i = %d ", i);
        Element* current = hashTable[i].table;
        while (current != NULL) {
            if (strcmp(value, getKey(current)) == 0) {
                
                return current;
            }
            current = getNextElement(current);
        }
    }
    return NULL;
}

Element* search(HashTable* segment, int sizeOfTable, const char* key) {
    int size = sizeOfTable;
    while (size > 1) {
        printf(" size = %d ", size);
        int index = hash(key, size);
        Element* found = searchByValueOfElement2(segment, size, key);
        if (found) {
            printf("  %s - %d  ", key, index);
            return found;
        }
        size /= 2;
    }
    
    return NULL;
}

/*Element* search(HashTable* segment, int sizeOfTable, const char* key) {
    return searchByValueOfElement2(segment, sizeOfTable, key);
}*/

void insert(HashTable* segment, int sizeOfTable, const char* key, bool* errorCode) {
    //printf("  !%s!  ", key);
    Element* found = search(segment, sizeOfTable, key);
    if (found) {
        incrementValueCount(found);
        return;
    }
    int index = hash(key, sizeOfTable);
    push(&(segment[index].table), key, errorCode);
}

void freeTable(HashTable* hashTable, int sizeOfTable) {
    for (int i = 0; i < sizeOfTable; ++i) {
        Element* current = hashTable[i].table;
        pop(&(current));
    }
    free(hashTable);
}

void hashTableSize(HashTable** table, int sizeOfTable, bool* errorCode) {
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

int* calculate(HashTable* segment, int sizeOfTable, int arraySize) {
    int* task = malloc(3 * sizeof(int));
    task[0] = arraySize;
    //task[0] = arraySize / HASH_TABLE_SIZE;

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
        task[1] = length;
        //task[1] = (float)length / arraySize;
    }
    task[2] = max;
    //task[2] = (float)max;
    return task;
}

HashTable* fillOutTheTable(const char* array[], int* sizeOfTable, int arraySize, bool* errorCode, int** task) {
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
            hashTableSize(&segment, *sizeOfTable, errorCode);
            if (!*errorCode) {
                freeTable(segment, *sizeOfTable);
                return NULL;
            }
        }
    }

    *task = calculate(segment, *sizeOfTable, arraySize);
    return segment;
}


int printTable(const char* array[], int arraySize, bool* errorCode, int** task) {
    int sizeofTable = 100;
    HashTable* hashTable = fillOutTheTable(array, &sizeofTable, arraySize, errorCode, task);
    for (int i = 0; i < sizeofTable; ++i) {
        printElements(hashTable[i].table);
    }
    freeTable(hashTable, sizeofTable);
    return sizeofTable;
}

void solution(const char* array[], int arraySize, bool* errorCode, int** task) {
    int sizeofTable = 100;
    HashTable* hashTable = fillOutTheTable(array, &sizeofTable, arraySize, errorCode, task);
    freeTable(hashTable, sizeofTable);
}
