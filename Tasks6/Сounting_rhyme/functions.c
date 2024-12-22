#include "functions.h"
#include <stdlib.h>

void push(Element** front, int value) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value;
    element->next = (*front)->next;
    (*front)->next = element;
}

void deleteElement(Element* front) {
    Element* delete = front->next;
    front->next = front->next->next;
    free(delete);
}