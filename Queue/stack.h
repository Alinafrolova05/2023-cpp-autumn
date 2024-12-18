#ifndef STACK
#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element* next;

}Element;

void enqueue(Element** head, int value);

void dequeue(Element** first, Element** second);

void queue(Element** first, Element** second, int value);

bool test();
#endif