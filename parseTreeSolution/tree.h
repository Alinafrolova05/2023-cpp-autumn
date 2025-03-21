#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Tree Tree;

void setValue(Tree** element, int value);

// Prints tree.
void printTree(Tree* element);

// Builds a tree.
Tree* tree(char* str, bool* errorCode);

// Calculates the result of an arithmetic expression.
int countResult(char* str, bool* errorCode);

// Removes a tree.
void freeTree(Tree** element);
