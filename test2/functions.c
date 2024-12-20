#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE_TABLE 100

Hash_table* createTable(void) {
    Hash_table* hash_table = calloc(1, sizeof(Hash_table));
    hash_table->table = calloc(SIZE_TABLE, sizeof(Element*));
    return hash_table;
}

int hash(char element) {
    return element / 5;
}

void insert(Hash_table* hash_table, char key) {
    int index = hash(key);
    Element* element = calloc(1, sizeof(Element));

    element->key = key;
    element->next = NULL;

    if (hash_table->table[index] == NULL) {
        hash_table->table[index] = element;
    }
    else {
        Element* other = hash_table->table[index];
        while (other->next != NULL) {
            other = other->next;
        }
        other->next = element;
    }
}

int search(Hash_table* hash_table, char key) {
    int index = hash(key);
    Element* pointer = hash_table->table[index];
    int count = 0;
    while (pointer != NULL) {
        if (pointer->key == key) {
            return 0;
        }
        pointer = pointer->next;
    }
    return -1;
}

void freeTable(Hash_table* hash_table) {
    for (int i = 0; i < SIZE_TABLE; i++) {
        Element* element = hash_table->table[i];
        while (element != NULL) {
            Element* toFree = element;
            element = element->next;
            free(toFree);
        }
    }
    free(hash_table->table);
    free(hash_table);
}

int test(void) {
    Hash_table* hash_table = createTable();
    char string[] = { 'h', 's', 'a', 'f', 'j' };
    for (int i = 0; i < 6; ++i) {
        insert(hash_table, string[i]);
    }
    int uncorrect = 0;
    if (search(hash_table, 'a') != 0) {
        uncorrect++;
    }
    if (search(hash_table, 'z') != 1) {
        uncorrect++;
    }
    freeTable(hash_table);
    return uncorrect;
}
