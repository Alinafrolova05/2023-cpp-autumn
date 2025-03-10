#include "stack.h"
#include "balance.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
    char value;
    struct Element* next;
} Element;

Element* createElement(void) {
    return calloc(1, sizeof(Element));
}

char top(Element* element) {
    return element->value;
}

void push(Element** head, char value, bool* errorCode) {
    Element* element = createElement();
    if (element == NULL) {
        *errorCode = false;
        return;
    }
    element->value = value;
    element->next = *head;
    *head = element;
}

void pop(Element** element) {
    if (*element == NULL) return;
    Element* tmp = *element;
    *element = (*element)->next;
    free(tmp);
}
