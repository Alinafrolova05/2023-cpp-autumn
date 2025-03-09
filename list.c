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

Element* getNextElement(Element* element) {
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

void setNextElement(Element** element) {
    *element = (*element)->next;
}

void incrementValueCount(Element* element) {
    if (element != NULL) {
        element->count++;
    }
}

Element* createElement(void) {
    return calloc(1, sizeof(Element));
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

void printElements(Element* element) {
    while (element != NULL) {
        printf("%s   %d\n", element->key, element->count);
        element = element->next;
    }
}

Element* searchByValueOfElement(Element* element, char* value) {
    while (element != NULL) {
        if (strcmp(value, element->key) == 0) {
            return element;
        }
        element = element->next;
    }
    return element;
}
