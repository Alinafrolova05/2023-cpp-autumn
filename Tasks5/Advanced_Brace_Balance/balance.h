#ifndef ADVANCED_BRACE_BALANCE

#include <stdbool.h>

typedef struct Element {
    char brace;
    struct Element* next;
}Element;

void push(Element** element1, char brace1);
//adds an element to the stack

void pop(Element** element1);
//removes an element from the stack

void processBraces(char* str, Element** element1);
//removes valid elements from the stack

bool test();

#endif