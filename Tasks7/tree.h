#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Dictionary Dictionary;

// Creates the string.
char* createString(bool* errorCode);

// Copies the string.
char* myStrdup(const char* str, bool* errorCode);

// Returns the value stored in the structure.
char* getValue(Dictionary* node);

// Creates structure.
Dictionary* createNode(void);

// Frees the memory occupied by the tree.
void freeTree(Dictionary* root);

// Checks if the input is an integer.
void checkScanf(int* add, bool* errorCode);

// Searches for a node in the tree by key.
Dictionary* search(Dictionary* root, int key);

// Adds an element to the tree.
void addElement(Dictionary** root, int key, char* value, bool* errorCode);

// Deletes an element from the tree by key.
void deleteElement(Dictionary** root, int key, bool* errorCode);
