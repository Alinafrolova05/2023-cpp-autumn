#pragma once

#ifndef ADVANCED_BRACE_BALANCE
#define ADVANCED_BRACE_BALANCE

#include <stdbool.h>

typedef struct Element Element;

// Adds an element to the stack
void push(Element** element1, char value, bool* errorCode);

// Removes an element from the stack
void pop(Element** element1);

// Processes braces in the input string and removes valid elements from the stack
void processBraces(char* str, Element** element1, bool* errorCode);

// Runs tests to validate the functionality of the stack operations
bool test(void);

#endif
