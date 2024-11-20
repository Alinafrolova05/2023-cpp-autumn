#ifndef TREE
#include <stdbool.h>
typedef struct Element {
    int key;
    char* value;
}Element;
typedef struct Node {
    struct Node* parent;
    Element* element;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
bool testScanf(int result);
void Scanf(int* add);

Element* search(Node* root, int key1);
void add(Node* root, int key1, char* value1);
void deleteElement(Node* root, int key1);
#endif