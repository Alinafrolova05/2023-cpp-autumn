#include "stack.h"
#include "operations.h"
#include <stdio.h>
#include <malloc.h>
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

void setTop(Element** element, char value) {
    (*element)->value = value;
}

void setToNextElement(Element** element, Element* next) {
    (*element)->next = next;
}

void setNextElement(Element** element, Element* anotherElement) {
    *element = anotherElement->next;
}

void push(Element** head, char value, bool* errorCode) {
    Element* element = createElement();
    if (element == NULL) {
        *errorCode = false;
        return;
    }
    setTop(&element, value);
    setToNextElement(&element, *head);
    *head = element;
}

void pop(Element** element) {
    if (*element == NULL) return;
    Element* tmp = *element;
    setNextElement(element, *element);
    free(tmp);
    return;
}
