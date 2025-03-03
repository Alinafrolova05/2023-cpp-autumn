#include <stdio.h>
#include "stack.h"

void push(Element** head, int vertex, int weight, bool* errorCode) {
    Element* element = createElement();
    if (element == NULL) {
        *errorCode = false;
        return;
    }
    setValueVertex(&element, vertex);
    setValueWeight(&element, weight);
    setToNextElement(&element, *head);
    *head = element;
}

void pop(Element** head) {
    if (*head == NULL) return;
    Element* tmp = *head;
    setNextElement(head);
    free(tmp);
}
