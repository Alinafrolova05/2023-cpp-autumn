#pragma once

#include <stdbool.h>

// Definition of the Node structure for the AVL tree
typedef struct Dictionary Dictionary;

// Returns the value.
const char* getValue(Dictionary* node);

// Returns the balance.
int getBalance(Dictionary* node);

// Returns the left child.
Dictionary* getLeftChild(Dictionary* node);

// Returns the right child.
Dictionary* getRightChild(Dictionary* node);

// Frees the memory allocated for the entire tree
void freeTree(Dictionary** root);

// Balances the given node and returns the new root of the subtree if a rotation is necessary
Dictionary* balance(Dictionary* node);

// Inserts a new key-value pair into the AVL tree and returns the new root of the tree
// Sets errorCode to false if an error occurs during insertion
Dictionary* insert(Dictionary** root, const char* key, const char* value, bool* errorCode);

// Searches for a node with the specified key in the tree and returns a pointer to the node
Dictionary* search(Dictionary** root, const char* key);

// Deletes the node with the specified key from the tree and returns the new root of the tree
// Sets errorCode to false if the key is not found
Dictionary* deleteElement(Dictionary** root, const char* key, bool* errorCode);
