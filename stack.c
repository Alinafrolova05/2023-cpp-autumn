#include "stack.h"
#include <stdio.h>
#include <malloc.h>

typedef struct Element {
    int value;
    struct Element* next;
}Element;

void push(Element** element1, int value, bool* errorCode) {
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
