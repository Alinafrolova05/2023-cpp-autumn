#include "functions.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(Node* root) {
    if (root == NULL) return;
    print(root->leftChild);
    printf(" %d", root->element->key);
    print(root->rightChild);
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->leftChild);
        freeTree(root->rightChild);
        free(root->element);
        free(root);
    }
}

bool testScanf(int result) {
    return result == 1;
}

void Scanf(int* add) {
    int result = scanf("%d", add);
    if (!testScanf(result)) {
        printf("\nInput wrong!");
        exit(EXIT_FAILURE);
    }
}

Node* search(Node* root, int key1) {
    while (root != NULL) {
        if (key1 < root->element->key) {
            root = root->leftChild;
        }
        else if (key1 > root->element->key) {
            root = root->rightChild;
        }
        else {
            return root;
        }
    }
    return NULL;
}

void add(Node** root, int key1) {
    if (*root == NULL) {
        Node* node = calloc(1, sizeof(Node));
        Element* element1 = calloc(1, sizeof(Element));

        element1->key = key1;
        node->element = element1;
        node->leftChild = NULL;
        node->rightChild = NULL;
        *root = node;
        return;
    }

    Node* parent = NULL;
    Node* current = *root;

    while (current != NULL) {
        parent = current;
        if (key1 < current->element->key) {
            current = current->leftChild;
        }
        else if (key1 > current->element->key) {
            current = current->rightChild;
        }
        else {
            return;
        }
    }

    Node* node = calloc(1, sizeof(Node));
    Element* element1 = calloc(1, sizeof(Element));

    element1->key = key1;
    node->element = element1;
    node->leftChild = NULL;
    node->rightChild = NULL;

    if (key1 < parent->element->key) {
        parent->leftChild = node;
    }
    else {
        parent->rightChild = node;
    }
}

void deleteElement(Node** root, int key1) {
    Node* parent = NULL;
    Node* node = *root;

    while (node != NULL && node->element->key != key1) {
        parent = node;
        if (key1 < node->element->key) {
            node = node->leftChild;
        }
        else {
            node = node->rightChild;
        }
    }

    if (node == NULL) {
        printf("Element not found.\n");
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
        free(node->element);
        free(node);
    }
    else if (node->leftChild != NULL && node->rightChild != NULL) {
        Node* minNode = node->rightChild;
        while (minNode->leftChild != NULL) {
            minNode = minNode->leftChild;
        }

        node->element->key = minNode->element->key;
        deleteElement(&(minNode), minNode->element->key);
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

        free(node->element);
        free(node);
    }
}