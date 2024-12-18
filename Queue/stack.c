#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void enqueue(Element** head, int value) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value;
    element->next = *head;
    *head = element;
}

void dequeue(Element** first, Element** second) {
    while (*first != NULL) {
        enqueue(second, (*first)->value);
        Element* tmp = *first;
        *first = (*first)->next;
        free(tmp);
    }
    Element* tmp = *second;
    *second = (*second)->next;
    free(tmp);
    while (*second != NULL) {
        enqueue(first, (*second)->value);
        Element* tmp = *second;
        *second = (*second)->next;
        free(tmp);
    }
}

void queue(Element** first, Element** second, int value) {
    enqueue(first, value);
    dequeue(first, second);
}

bool test() {
    Element* first = NULL;
    Element* second = NULL;
    enqueue(&first, 1);
    enqueue(&first, 2);
    enqueue(&first, 3);
    queue(&first, &second, 4);
    int a = first->value;
    int b = 0;
    while (first->next != NULL) {
        b = first->value;
        Element* tmp = first;
        first = first->next;
        free(tmp);
    }
    free(first);
    free(second);
    return a == 4 && b == 2;
}
