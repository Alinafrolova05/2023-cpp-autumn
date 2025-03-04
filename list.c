#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include "list.h"

typedef struct Element {
    int value;
    struct Element* next;
} Element;

int getElementValue(Element* element) {
    return element->value;
}

Element* elementNext(Element* element) {
    if (element == NULL || element->next == NULL) return NULL;
    return element->next;
}

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void addElement(Element** head, int value, bool* errorCode) {
    Element* element = calloc(1, sizeof(Element));
    if (element == NULL) {
        *errorCode = false;
        return;
    }

    element->value = value;

    if (*head == NULL || (*head)->value >= value) {
        element->next = *head;
        *head = element;
        return;
    }

    Element* current = *head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    element->next = current->next;
    current->next = element;
}

void deleteElement(Element** head, int value) {
    if (head == NULL || *head == NULL) {
        return;
    }

    Element* current = *head;
    Element* previous = NULL;

    while (current != NULL && current->value < value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL || current->value != value) {
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    }
    else {
        previous->next = current->next;
    }

    free(current);
}


void freeList(Element** element) {
    while (*element != NULL) {
        pop(element);
    }
}
