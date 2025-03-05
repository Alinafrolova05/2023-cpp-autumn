#include "stack.h"
#include <malloc.h>

void push(Element** front, int value) {
    Element* element = createElement();
    if (element == NULL) {
        return;
    }
    setValue(&element, value);
    setNextElement(&element, getNext(*front));
    setNextElement(front, element);
}

void deleteElement(Element** front) {
    if (*front == NULL || getNext(*front) == NULL) return;
    Element* delete = getNext(*front);
    setNextElement(front, getNext(delete));
    free(delete);
}
