#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Node {
    int key;
    char* value;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

char* getValue(Node* node) {
    return node->value;
}

Node* createNode(void) {
    return NULL;
}

void checkScanf(int* add, bool* errorCode) {
    int result = scanf("%d", add);
    if (result != 1) {
        *errorCode = false;
        return;
    }
}

Node* search(Node* root, int key) {
    while (root != NULL) {
        if (key < root->key) {
            root = root->leftChild;
        }
        else if (key > root->key) {
            root = root->rightChild;
        }
        else {
            return root;
        }
    }
    return NULL;
}

void addElement(Node** root, int key, char* value, bool* errorCode) {
    if (*root == NULL) {
        Node* node = malloc(sizeof(Node));
        if (node == NULL) {
            *errorCode = false;
            return;
        }

        node->key = key;
        node->value = value;
        node->leftChild = NULL;
        node->rightChild = NULL;
        *root = node;
        return;
    }

    Node* parent = NULL;
    Node* current = *root;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->leftChild;
        }
        else if (key > current->key) {
            current = current->rightChild;
        }
        else {
            free(current->value);
            current->value = value;
            return;
        }
    }

    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        *errorCode = false;
        return;
    }

    node->key = key;
    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;

    if (key < parent->key) {
        parent->leftChild = node;
    }
    else {
        parent->rightChild = node;
    }
}

void deleteElement(Node** root, int key, bool* errorCode) {
    Node* parent = NULL;
    Node* node = *root;
    
    while (node != NULL && node->key != key) {
        parent = node;
        if (key < node->key) {
            node = node->leftChild;
        }
        else {
            node = node->rightChild;
        }
    }

    if (node == NULL) {
        *errorCode = false;
        return;
    }

    if (node->leftChild == NULL && node->rightChild == NULL) {
        if (parent == NULL) {
            *root = NULL;
        }
        else if (parent->leftChild == node) {
            parent->leftChild = NULL;
        }
        else {
            parent->rightChild = NULL;
        }
        free(node->value);
        free(node);
    }
    else if (node->leftChild != NULL && node->rightChild != NULL) {
        Node* minNode = node->rightChild;
        while (minNode->leftChild != NULL) {
            minNode = minNode->leftChild;
        }

        node->key = minNode->key;
        free(node->value);
        node->value = minNode->value;

        deleteElement(&(minNode), minNode->key, errorCode);
    }
    else {
        Node* child = NULL;
        if (node->leftChild != NULL) {
            child = node->leftChild;
        }
        else {
            child = node->rightChild;
        }

        if (parent == NULL) {
            *root = child;
        }
        else if (parent->leftChild == node) {
            parent->leftChild = child;
        }
        else {
            parent->rightChild = child;
        }

        free(node->value);
        free(node);
    }
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root->value);
    free(root);
}
