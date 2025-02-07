#include "stack.h"
#include "balance.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

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
}
