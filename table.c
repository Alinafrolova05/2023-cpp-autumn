#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "table.h"

typedef struct Element {
    char* key;
    int hash;
    int count;
    struct Element* next;
} Element;

typedef struct Segment {
    Element* table;
    struct Segment* next;
} Segment;

Element* getValue1(Segment* segment) {
    return segment->table;
}

char* getValue2(Element* element) {
    return element->key;
}

int getValue3(Element* element) {
    return element->count;
}

Segment* getValue4(Segment* segment) {
    return segment->next;
}

Element* getValue5(Element* element) {
    return element->next;
}

char* myStrdup(char* str, bool* errorCode) {
    if (str == NULL) return NULL;
    size_t len = strlen(str) + 1;
    char* copy = malloc(len);
    if (copy) {
        strcpy(copy, str);
    }
    else {
        *errorCode = false;
    }
    return copy;
}

Segment* createSegment(bool* errorCode) {
    Segment* hashTable = calloc(1, sizeof(Segment));
    if (hashTable == NULL) {
        *errorCode = false;
        return NULL;
    }
    hashTable->table = NULL;
    hashTable->next = NULL;
    return hashTable;
}

bool search(Segment* segment, char* key) {
    int index = getValueHash(key);
    while (segment != NULL) {
        if (segment->table != NULL && segment->table->hash == index) {
            Element* current = segment->table;
            while (current != NULL) {
                if (strcmp(key, current->key) == 0) {
                    current->count++;
                    return true;
                }
                current = current->next;
            }
        }
        segment = segment->next;
    }
    return false;
}

void insert(Segment** segment, char* key, bool* errorCode) {
    if (search(*segment, key)) {
        return;
    }

    int index = getValueHash(key);
    Element* element = malloc(sizeof(Element));
    if (element == NULL) {
        *errorCode = false;
        return;
    }

    element->key = myStrdup(key, errorCode);
    if (!(*errorCode)) {
        free(element);
        return;
    }
    element->count = 1;
    element->hash = index;
    element->next = NULL;

    if (*segment == NULL) {
        *segment = createSegment(errorCode);
        if (!(*errorCode)) {
            free(element->key);
            free(element);
            return;
        }
    }

    Segment* current = *segment;
    while (current != NULL) {
        if (current->table == NULL || current->table->hash >= index) {
            element->next = current->table;
            current->table = element;
            return;
        }
        current = current->next;
    }

    Segment* newTable = createSegment(errorCode);
    if (!(*errorCode)) {
        free(element->key);
        free(element);
        return;
    }
    newTable->table = element;
    newTable->next = *segment;
    *segment = newTable;
}

void freeSegments(Segment** segment) {
    while (*segment != NULL) {
        Segment* temp = *segment;
        while (temp->table != NULL) {
            Element* element = temp->table;
            temp->table = temp->table->next;
            free(element->key);
            free(element);
        }
        *segment = (*segment)->next;
        free(temp);
    }
}
