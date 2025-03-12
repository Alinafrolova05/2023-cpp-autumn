#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

typedef struct HashTable {
    Element** table;
    int size;
    int elementCount;
} HashTable;

int getSizeTable(HashTable* table) {
    return table->size;
}

int getHashTableElementCount(HashTable* table) {
    return table->elementCount;
}

HashTable* createHashTable(int initialSize, bool* errorCode) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (!hashTable) {
        *errorCode = false;
        return NULL;
    }

    hashTable->table = createElementArray(initialSize);
    if (!hashTable->table) {
        free(hashTable);
        *errorCode = false;
        return NULL;
    }

    hashTable->size = initialSize;
    hashTable->elementCount = 0;
    return hashTable;
}

void freeTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; ++i) {
        Element* current = hashTable->table[i];
        while (current) {
            Element* temp = current;
            current = getNextElement(current);
            free(getKey(temp));
            free(temp);
        }
    }
    free(hashTable->table);
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

Element* search(HashTable* hashTable, const char* key) {
    int index = hash(key, hashTable->size);
    Element* current = hashTable->table[index];
    while (current) {
        if (strcmp(getKey(current), key) == 0) {
            return current;
        }
        current = getNextElement(current);
    }
    return NULL;
}

void insert(HashTable* hashTable, const char* key, bool* errorCode) {
    Element* searchElement = search(hashTable, key);
    if (searchElement != NULL) {
        incrementValueCount(searchElement);
        return;
    }

    int index = hash(key, hashTable->size);
    Element* newElement = createElement();
    if (!newElement) {
        *errorCode = false;
        return;
    }

    setKey(newElement, myStrdup(key, errorCode));
    if (!*errorCode) {
        free(newElement);
        return;
    }
    incrementValueCount(newElement);
    hashTable->table[index] = newElement;
    hashTable->elementCount++;
}

void resizeHashTable(HashTable** table, bool* errorCode) {
    int newSize = (*table)->size * 2;
    HashTable* newTable = createHashTable(newSize, errorCode);
    if (!*errorCode) {
        return;
    }

    for (int i = 0; i < (*table)->size; ++i) {
        Element* current = (*table)->table[i];
        while (current) {
            insert(newTable, getKey(current), errorCode);
            if (!*errorCode) {
                freeTable(newTable);
                return;
            }
            current = getNextElement(current);
        }
    }

    freeTable(*table);
    *table = newTable;
}

void insertInTable(HashTable* hashTable, const char* key, bool* errorCode) {
    if ((float)getHashTableElementCount(hashTable) / getSizeTable(hashTable) > 0.7) {
        resizeHashTable(&hashTable, errorCode);
        if (!*errorCode) {
            printf("Error!!!");
            freeTable(hashTable);
            return;
        }
    }
    insert(hashTable, key, errorCode);
    if (!*errorCode) {
        printf("Error!!!");
        freeTable(hashTable);
        return;
    }
}

void printTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; ++i) {
        Element* current = hashTable->table[i];
        if (current) {
            while (current) {
                printf("%s    %d\n", getKey(current), getCount(current));
                current = getNextElement(current);
            }
        }
    }
}

double calcuHashTableFillFactor(HashTable* hashTable) {
    return (double)hashTable->elementCount / hashTable->size;
}

double calcuLateAverageListLength(HashTable* hashTable) {
    int totalLength = 0;
    for (int i = 0; i < hashTable->size; ++i) {
        Element* current = hashTable->table[i];
        int len = 0;
        while (current) {
            len++;
            current = getNextElement(current);
        }
        totalLength += len;
    }
    return (double)totalLength / hashTable->size;
}

int calcuLateMaxListLength(HashTable* hashTable) {
    int maxLength = 0;
    for (int i = 0; i < hashTable->size; ++i) {
        Element* current = hashTable->table[i];
        int len = 0;
        while (current) {
            len++;
            current = getNextElement(current);
        }
        if (len > maxLength) {
            maxLength = len;
        }
    }
    return maxLength;
}
