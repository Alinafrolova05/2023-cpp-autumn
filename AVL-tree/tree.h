#ifndef TREE
typedef struct Node {
    int key;
    char* value;
    int balance;
    struct Node* left;
    struct Node* right;
}Node;

void freeTree(Node* root);

Node* rotateLeft(Node* node);

Node* rotateRight(Node* node);

Node* bigRotateLeft(Node* node);

Node* bigRotateRight(Node* node);

Node* balance(Node* node);

Node* insert(Node** root, Node* node);

Node* deleteElement(Node* root, int key);

Node* search(Node* root, int key);

#endif