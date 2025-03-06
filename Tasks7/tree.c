#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Dictionary {
    int key;
    char* value;
    struct Dictionary* leftChild;
    struct Dictionary* rightChild;
}Dictionary;

char* createString(bool* errorCode) {
    char* newStr = (char*)calloc(256, sizeof(char));
    if (newStr == NULL) {
        *errorCode = false;
        return NULL;
    }
    return newStr;
}

char* myStrdup(const char* str, bool* errorCode) {
    if (str == NULL) {
        *errorCode = false;
        return NULL;
    }
    size_t len = strlen(str) + 1;
    char* copy = malloc(len);
    if (copy) {
        strcpy(copy, str);
    }
    else {
        *errorCode = false;
    }
    return copy;
}

char* getValue(Dictionary* node) {
    return node->value;
}

Dictionary* createNode(void) {
    return NULL;
}

void checkScanf(int* add, bool* errorCode) {
    int result = scanf("%d", add);
    if (result != 1) {
        *errorCode = false;
        return;
    }
}

Dictionary* search(Dictionary* root, int key) {
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

void addElement(Dictionary** root, int key, char* value, bool* errorCode) {
    if (*root == NULL) {
        Dictionary* node = malloc(sizeof(Dictionary));
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

    Dictionary* parent = NULL;
    Dictionary* current = *root;

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

    Dictionary* node = malloc(sizeof(Dictionary));
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

void deleteElement(Dictionary** root, int key, bool* errorCode) {
    Dictionary* parent = NULL;
    Dictionary* node = *root;
    
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
        Dictionary* minNode = node->rightChild;
        while (minNode->leftChild != NULL) {
            minNode = minNode->leftChild;
        }

        node->key = minNode->key;
        free(node->value);
        node->value = minNode->value;

        deleteElement(&(minNode), minNode->key, errorCode);
    }
    else {
        Dictionary* child = NULL;
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

void freeTree(Dictionary* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root->value);
    free(root);
}
