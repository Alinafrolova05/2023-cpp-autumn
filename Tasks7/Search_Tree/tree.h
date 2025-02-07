#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Node Node;

// Returns the value stored in the structure.
char* getValue(Node* node);

// Creates structure.
Node* createNode(void);

// Frees the memory occupied by the tree.
void freeTree(Node* root);

// Checks if the input is an integer.
void checkScanf(int* add, bool* errorCode);

// Searches for a node in the tree by key.
Node* search(Node* root, int key);

// Adds an element to the tree.
void addElement(Node** root, int key, char* value, bool* errorCode);

// Deletes an element from the tree by key.
void deleteElement(Node** root, int key, bool* errorCode);

// Displays the menu with options.
void menu(Node** root);
