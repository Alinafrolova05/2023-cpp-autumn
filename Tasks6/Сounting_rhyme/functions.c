#include "functions.h"
#include <malloc.h>

void push(Element** head, int value, Element** firstElement) {
    Element* element = malloc(sizeof(Element));
    element->value = value;
    element->next = (*head);
    *head = element;
    if (element->value == 1) {
        (*firstElement)->next = element;
    }
}

void deleteElement(Element* front) {
    Element* delete = front->next;
    front->next = front->next->next;
    free(delete);
}