#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Element Element; 

// Increments the count of a element.
void incrementValueCount(Element* element);

// Adds a new value to the head of the list.
void push(Element** head, char* value, bool* errorCode);

// Removes the element from the head of the list.
void pop(Element** element);

// Prints all elements in the list.
void printElements(Element* element);

// Searches for a value in the list and returns the corresponding element.
Element* searchByValueOfElement(Element* element, char* value);
