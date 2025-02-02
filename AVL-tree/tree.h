#pragma once

#include <stdbool.h>

// Definition of the Node structure for the AVL tree
typedef struct Node Node;

// Frees the memory allocated for the entire tree
void freeTree(Node** root);

// Performs a left rotation on the given node and returns the new root of the subtree
Node* rotateLeft(Node* node);

// Performs a right rotation on the given node and returns the new root of the subtree
Node* rotateRight(Node* node);

// Performs a double left rotation (right-left case) on the given node and returns the new root of the subtree
Node* bigRotateLeft(Node* node);

// Performs a double right rotation (left-right case) on the given node and returns the new root of the subtree
Node* bigRotateRight(Node* node);

// Balances the given node and returns the new root of the subtree if a rotation is necessary
Node* balance(Node* node);

// Inserts a new key-value pair into the AVL tree and returns the new root of the tree
// Sets errorCode to false if an error occurs during insertion
Node* insert(Node** root, const char* key, const char* value, bool* errorCode);

// Searches for a node with the specified key in the tree and returns a pointer to the node
Node* search(Node** root, const char* key);

// Deletes the node with the specified key from the tree and returns the new root of the tree
// Sets errorCode to false if the key is not found
Node* deleteElement(Node** root, const char* key, bool* errorCode);

