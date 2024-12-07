#ifndef TREE
#include <stdbool.h>
typedef struct Element {
    int key;
    char* value;
}Element;
typedef struct Node {
    Element* element;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
void freeTree(Node* root);

bool testScanf(int result);

void Scanf(int* add);

Node* search(Node* root, int key1);

void add(Node** root, int key1, char* value1);

void deleteElement(Node** root, int key1);

#endif