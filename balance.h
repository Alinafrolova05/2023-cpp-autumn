#pragma once

#include <stdbool.h>

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

// Function to create a new element and return a pointer to it
Element* createElement(void);

// Function to process braces in the input string and remove valid elements from the stack
void processBraces(char* str, bool* errorCode, char check[]);
