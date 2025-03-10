#pragma once

#include <stdbool.h>
#include "stack.h"

// Defines the structure.
typedef struct Element Element;

// Adds an element to the top of the stack.
void push(Element** head, char value, bool* errorCode);

// Removes the top element from the stack.
void pop(Element** head);

// Converts an infix expression to postfix notation using stacks.
void processInput(char* str, Element** numbers, Element** operations, bool* errorCode);

// Solves the problem.
char* solution(char str[], bool* errorCode);
