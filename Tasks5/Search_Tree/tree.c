#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool testScanf(int result) {
    return result == 1;
}

void Scanf(int* add) {
    int result = scanf("%d", add);
    if (!testScanf(result)) {
        printf("\nInput wrong!");
        return -1;
    }
}

Element* search(Node* root, int key1) {
    while (true) {
        if (root->element->key < key1) {
            if (root->rightChild == NULL) {
                return root;
            }
            else {
                search(root->rightChild, key1);
            }
        }
        else if (root->element->key > key1) {
            if (root->leftChild == NULL) {
                return root;
            }
            else {
                search(root->leftChild, key1);
            }
        }
        else if (root->element->key == key1) {
            return root;
        }
    }
}

void add(Node* root, int key1, char* value1) {
    Node* previos = search(root, key1);
    if (previos->element->key == key1) {
        previos->element->value = value1;
        return;
    }
    else {
        Node* node = calloc(1, sizeof(Node));
        Element* element1 = calloc(1, sizeof(Element));
        element1->key = key1;
        element1->value = value1;

        node->parent = previos;
        node->element = element1;
        node->leftChild = NULL;
        node->rightChild = NULL;

        if (previos->element->key > key1) {
            previos->leftChild = node;
        }
        if (previos->element->key < key1) {
            previos->rightChild = node;
        }
    }
    return;
}

void deleteElement(Node* root, int key1) {
    Node* node = search(root, key1);
    if (node->element->key == key1) {
        if (node->leftChild == NULL && node->rightChild == NULL) {
            Node* tmp = node;
            node = node->parent;
            free(tmp);
        }
        else if (node->leftChild != NULL) {
            Node* tmp = node->leftChild;
            free(node->element->value);
            free(node->element);

            if (tmp->rightChild == NULL) {
                node->element = tmp->element;
                node->leftChild = tmp->leftChild;
                tmp->leftChild->parent = node;

                free(tmp->element->value);
                free(tmp->element);
                free(tmp);
                return;
            }

            while (tmp->rightChild != NULL) {
                tmp = tmp->rightChild;
            }
            node->element = tmp->element;
            if (tmp->leftChild != NULL) {
                tmp->leftChild->parent = tmp->parent;
                tmp->parent->rightChild = tmp->leftChild;
            }
            /*else {
                tmp->parent->rightChild = NULL;
            }*/
            free(tmp->element->value);
            free(tmp->element);
            free(tmp);
        }
        else {
            Node* tmp = node->rightChild;
            free(node->element->value);
            free(node->element);

            node->element = tmp->element;
            node->leftChild = tmp->leftChild;
            node->rightChild = tmp->rightChild;

            tmp->leftChild->parent = node;
            tmp->rightChild->parent = node;

            free(tmp->element->value);
            free(tmp->element);
            free(tmp);
        }
    }
}
