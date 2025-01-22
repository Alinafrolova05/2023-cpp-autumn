#pragma once

#ifndef MARSHALLING_YARD
#define MARSHALLING_YARD

#include <stdbool.h>

typedef struct Element Element;

// Adds an element to the top of the stack.
void push(Element** head, char value, bool* errorCode);

// Removes the top element from the stack.
void pop(Element** head);

// Converts an infix expression to postfix notation using stacks.
void processInput(char* str, Element** numbers, Element** operations, bool* errorCode);

// Runs tests to verify the functionality of the stack operations.
bool test(void);

#endif
