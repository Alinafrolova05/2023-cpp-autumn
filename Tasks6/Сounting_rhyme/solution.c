#include <stdio.h>
#include <malloc.h>
#include "stack.h"

typedef struct Element {
    int value;
    struct Element* next;
}Element;

Element* createElement(void) {
    return malloc(sizeof(Element));
}

int getValue(Element* element) {
    return element->value;
}

void setValue(Element** element, int value) {
    (*element)->value = value;
}

Element* getNext(Element* element) {
    if (element == NULL) return NULL;
    return element->next;
}

void setNextElement(Element** element, Element* anotherElement) {
    (*element)->next = anotherElement;
}

Element* count(Element** element, int value) {
    if (value <= 2) {
        return;
    }
    (*element)->value = value;
    for (int i = value - 1; i > 0; --i) {
        push(element, i);
    }

    int i = 1;
    *element = (*element)->next;
    while ((*element)->next->next->value != (*element)->value) {
        i++;
        if (i % 3 == 0) {
            deleteElement(element);
            i = 1;
        }
        *element = (*element)->next;
    }
    return *element;
}

Element* solution(int value) {
    Element* element = malloc(sizeof(Element));
    element->next = element;
    return count(&element, value);
}

void deleteLine(Element** element) {
    while (*element == NULL || (*element)->next != *element) {
        deleteElement(element);
    }
}
