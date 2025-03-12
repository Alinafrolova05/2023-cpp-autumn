#pragma once

#include <stdbool.h>

// Forward declaration of the Element struct.
typedef struct Element Element;

// Moves the pointer to the next element in the linked list.
void moveToNext(Element** element);

// Sets the next element pointer of the current element to another specified element.
void setToNextElement(Element** element, Element* anotherElement);

// Sets the vertex value for the specified element.
void setValueVertex(Element** element, int vertex);

// Sets the weight value for the specified element.
void setValueWeight(Element** element, int weight);

// Retrieves the vertex value from the specified element.
int getElementVertex(const Element* element);

// Retrieves the weight value from the specified element.
int getElementWeight(const Element* element);

// Returns the next element in the linked list from the specified element.
Element* getNextElement(const Element* element);

// Creates a new element and returns a pointer to it.
Element* createElement(void);

// Adds a new element with the specified vertex and weight to the front of the linked list.
void push(Element** head, int vertex, int weight, bool* errorCode);

// Removes the element at the front of the linked list, if it exists.
void pop(Element** head);
