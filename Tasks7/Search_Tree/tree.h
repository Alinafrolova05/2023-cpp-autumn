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
//frees the tree

void Scanf(int* add);
//checks if choice is an integer

Node* search(Node* root, int key1);

void add(Node** root, int key1, char* value1);
//adds in the tree

void deleteElement(Node** root, int key1);

void menu(Node** root);
//prints options

#endif