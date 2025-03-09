#pragma once

#include <stdbool.h>
#include "balance.h"

// Defines the structure.
typedef struct Element Element;

// Function to get the value of the top element in the stack
char top(Element* element);

// Function to set the value of the top element in the stack
void setTop(Element** element, char value);

// Function to set the next element of the current element to a given next element
void setToNextElement(Element** element, Element* next);

// Function to set another element to the next element of the current element.
void setNextElement(Element** element, Element* anotherElement);

// Clears the stack.
void popStack(Element* stack, char check[]);

// Function to create a new element and return a pointer to it
Element* createElement(void);

// Adds an element to the top of the stack.
void push(Element** head, char value, bool* errorCode);

// Removes the top element from the stack.
void pop(Element** head);
