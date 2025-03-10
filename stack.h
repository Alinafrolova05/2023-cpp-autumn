#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Stack Stack;

// Function to get the value of the top element in the stack.
char top(Stack* stack);

Stack* getNextElement(Stack* stack);

// Function to create a new element and return a pointer to it.
Stack* createElement(void);

// Adds an element to the top of the stack.
void push(Stack** head, char value, bool* errorCode);

// Removes the top element from the stack.
void pop(Stack** head);
