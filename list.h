#pragma once

#include <stdbool.h>

typedef struct Element Element;

// Returns the element's value.
int getElementValue(Element* element);

// Returns the next element.
Element* elementNext(Element* element);

// Adds a new element with the specified value to the stack.
void addElement(Element** head, int value, bool* errorCode);

// Deletes an element with the specified value from the stack.
void deleteElement(Element** head, int value);

// Removes the top element from the stack.
void pop(Element** head);

// Frees the memory allocated for the entire stack.
void freeList(Element** element);
