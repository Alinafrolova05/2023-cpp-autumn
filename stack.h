#pragma once

#ifndef STACK
#define STACK

#include <stdbool.h>

typedef struct Element Element;

// Adds an element to the top of the stack.
void push(Element** head, int value, bool* errorCode);

// Removes the top element from the stack.
void pop(Element** head);

// Runs tests to verify the functionality of the stack implementation.
bool test(void);

#endif
