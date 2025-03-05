#pragma once

// Defines the structure.
typedef struct Element Element;

// Creates an element.
Element* createElement(void);

// Returns the element's value.
int getValue(Element* element);

// Sets the element's value.
void setValue(Element** element, int value);

// Returns the next element.
Element* getNext(Element* element);

// Sets the next element.
void setNextElement(Element** element, Element* anotherElement);

// Solves the problem.
Element* solution(int value);

// Removes elements.
void deleteLine(Element** element);
