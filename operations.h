#pragma once

#ifndef POSTFIX_CALCULATOR
#define POSTFIX_CALCULATOR

#include <stdbool.h>

// Forward declaration of the Element structure
typedef struct Element Element;

// Function to add an element to the stack
void push(Element** head, int value, bool* errorCode);

// Function to remove an element from the stack
void pop(Element** head2);

// Function that performs one of the arithmetic operations
void performOperation(Element* element1, char str, int* answer, bool* errorCode);

// Function that either calls the "push" function or the "operation" function
void processNumbers(Element* element1, char str[], int* answer, bool* errorCode);

// Function to test the correctness of the result
bool testStackOperations(void);

#endif
