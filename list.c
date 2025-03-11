#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Element {
    char* key;
    int count;
    struct Element* next;
} Element;

char* getKey(Element* element) {
    return element->key;
}

void* setKey(Element* element, char* key) {
    element->key = key;
}

int getCount(Element* element) {
    return element->count;
}

Element* getNextElement(Element* element) {
    return element->next;
}

Element* createElement(void) {
    return calloc(1, sizeof(Element));
}

Element** createpointerElement(int initialSize) {
    return(Element**)calloc(initialSize, sizeof(Element*));
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

void incrementValueCount(Element* element) {
    if (element != NULL) {
        element->count++;
    }
}

void push(Element** head, char* value, bool* errorCode) {
    Element* element = createElement();
    if (element == NULL) {
        *errorCode = false;
        return;
    }
    element->key = myStrdup(value, errorCode);
    if (element->key == NULL) {
        *errorCode = false;
        return;
    }
    element->count = 1;
    element->next = *head;
    *head = element;
}

void pop(Element** element) {
    if (*element == NULL) return;
    Element* tmp = *element;
    *element = tmp->next;
    free(tmp->key);
    free(tmp);
    return;
}
