#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Element {
    int vertex;
    int weight;
    struct Element* next;
} Element;

void moveToNext(Element** element) {
    *element = (*element)->next;
}

void setToNextElement(Element** element, Element* anotherElement) {
    (*element)->next = anotherElement;
}

void setValueVertex(Element** element, int vertex) {
    (*element)->vertex = vertex;
}

void setValueWeight(Element** element, int weight) {
    (*element)->weight = weight;
}

int getElementVertex(const Element* element) {
    return element->vertex;
}

int getElementWeight(const Element* element) {
    return element->weight;
}

Element* getNextElement(const Element* element) {
    return element->next;
}

Element* createElement(void) {
    return calloc(1, sizeof(Element));
}

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
    moveToNext(head);
    free(tmp);
}
