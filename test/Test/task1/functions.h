#ifndef FUNCTIONS
#include <stdbool.h>
typedef struct Element {
    int key;
}Element;
typedef struct Node {
    Element* element;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
void freeTree(Node* root);
//deletes tree
bool testScanf(int result);
//checks scanf value
void Scanf(int* add);
//reads and checks the value
Node* search(Node* root, int key1);
//searchs an element in binary tree
void add(Node** root, int key1);
//adds an element to a binary tree
void deleteElement(Node** root, int key1);
//removes an element from a binary tree
void print(Node* root);
//prints tree
#endif