#include <stdio.h>
#include <stdlib.h>
#include "module.h"

void push(Element** element1, char brace1) {
    Element* element = calloc(1, sizeof(Element));
    element->brace = brace1;
    element->next = *element1;
    *element1 = element;
}

void pop(Element** element1) {
    Element* tmp = *element1;
    *element1 = (*element1)->next;
    free(tmp);
}
