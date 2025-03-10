#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Element Element;

// Returns the element's value.
char getValueOfElement(Element* element);

// Returns the next element.
Element* getNextElement(Element* element);

// Adds an element to the top of the stack.
void push(Element** head, char value, bool* errorCode);

// Removes the top element from the stack.
void pop(Element** head);
