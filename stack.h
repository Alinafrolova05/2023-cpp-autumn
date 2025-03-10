#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Element Element;

// Function to get the value of the top element in the stack
char top(Element* element);

// Function to create a new element and return a pointer to it
Element* createElement(void);

// Adds an element to the top of the stack.
void push(Element** head, char value, bool* errorCode);

// Removes the top element from the stack.
void pop(Element** head);
