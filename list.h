#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Element Element; 

// Returns the key.
char* getKey(Element* element);

// Sets the key for the given element.
void* setKey(Element* element, char* key);

// Returns the count of the given element.
int getCount(Element* element);

// Returns a pointer to the next element
Element* getNextElement(Element* element);

// Creates and returns a new element.
Element* createElement(void);

// Creates and returns an array of pointers to elements with the specified initial size.
Element** createpointerElement(int initialSize);

// Duplicates the given string and returns a pointer to the new string.
char* myStrdup(char* str, bool* errorCode);

// Increments the count of a element.
void incrementValueCount(Element* element);

// Adds a new value to the head of the list.
void push(Element** head, char* value, bool* errorCode);

// Removes the element from the head of the list.
void pop(Element** element);
