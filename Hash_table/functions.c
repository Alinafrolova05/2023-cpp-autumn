#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE_TABLE 100

Hash_table* createTable() {
    Hash_table* hash_table = calloc(1, sizeof(Hash_table));
    hash_table->table = calloc(SIZE_TABLE, sizeof(Element*));
    return hash_table;
}

void insert(Hash_table* hash_table, char* key) {
    int index = hash(key);
    Element* element = calloc(1, sizeof(Element));

    element->key = malloc(strlen(key) + 1);
    strcpy(element->key, key);

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

int search(Hash_table* hash_table, char* key) {
    int index = hash(key);
    Element* pointer = hash_table->table[index];
    int count = 0;
    while (pointer != NULL) {
        if (strcmp(key, pointer->key) == 0) {
            count++;
        }
        pointer = pointer->next;
    }
    return count;
}

void freeTable(Hash_table* hash_table) {
    for (int i = 0; i < SIZE_TABLE; i++) {
        Element* element = hash_table->table[i];
        while (element != NULL) {
            Element* toFree = element;
            element = element->next;
            free(toFree->key);
            free(toFree);
        }
    }
    free(hash_table->table);
    free(hash_table);
}

int test() {
    Hash_table* hash_table = createTable();
    insert(hash_table, "apple");
    insert(hash_table, "april");
    insert(hash_table, "orange");
    insert(hash_table, "orange");
    int correct = 0;
    if (search(hash_table, "apple") == 1) {
        correct++;
    }
    if (search(hash_table, "orange") == 2) {
        correct++;
    }
    freeTable(hash_table);
    return correct;
}
