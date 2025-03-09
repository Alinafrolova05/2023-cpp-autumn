#include "stack.h"
#include <stdio.h>
#include <malloc.h>

typedef struct Element {
    char value;
    struct Element* next;
}Element;

char getValueOfElement(Element* element) {
    return element->value;
}

Element* getNextElement(Element* element) {
    return element->next;
}

void push(Element** element1, char value, bool* errorCode) {
    Element* element = malloc(sizeof(Element));
    if (element == NULL) {
        *errorCode = false;
        return;
    }
    element->value = value;
    element->next = *element1;
    *element1 = element;
}

void pop(Element** element1) {
    if (*element1 == NULL) return;
    Element* tmp = *element1;
    *element1 = (*element1)->next;
    free(tmp);
}
