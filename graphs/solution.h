#pragma once

#include <stdbool.h>
#include <stdio.h>

// Forward declaration of the Element structure.
typedef struct Element Element;

// Forward declaration of the Table structure.
typedef struct Table Table;

// Main function to solve the problem using data from the specified file 
// and returns a table of cities in each state.
Table* fillOutTable(FILE* file, int* numberOfStates, bool* errorCode);

// Fills in a table of states.
void solve(Table* table, Table* states, int size, int stateCount, bool* errorCode);

// Creates a new element.
Element* createElement(void);

// Creates a new table of the specified size.
Table* createTable(int size, bool* errorCode);

// Sets the next element for the element.
void moveToNext(Element** element);

// Sets the another element to next element for the element.
void setToNextElement(Element** element, Element* anotherElement);

// Sets the vertex value for the element.
void setValueVertex(Element** element, int vertex);

// Sets the weight value for the element.
void setValueWeight(Element** element, int weight);

// Reads data from the file and creates a table.
Table* loadFromFile(FILE* file, int* size, bool* errorCode);

// Prints the contents of the table.
void printTable(Table* states, int size);

// Deletes the table and frees the allocated memory.
void deleteTable(Table** segment, int size);
