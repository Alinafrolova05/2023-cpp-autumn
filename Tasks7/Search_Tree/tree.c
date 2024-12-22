#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->leftChild);
        freeTree(root->rightChild);
        free(root->element->value);
        free(root->element);
        free(root);
    }
}

void Scanf(int* add) {
    int result = scanf("%d", add);
    if (result != 1) {
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

void add(Node** root, int key1, char* value1) {
    if (*root == NULL) {
        Node* node = calloc(1, sizeof(Node));
        Element* element1 = calloc(1, sizeof(Element));

        element1->key = key1;
        element1->value = value1;
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
            char* tmp = current->element->value;
            current->element->value = value1;
            free(tmp);
            return;
        }
    }

    Node* node = calloc(1, sizeof(Node));
    Element* element1 = calloc(1, sizeof(Element));

    element1->key = key1;
    element1->value = value1;
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
        free(node->element->value);
        free(node->element);
        free(node);
    }
    else if (node->leftChild != NULL && node->rightChild != NULL) {
        Node* minNode = node->rightChild;
        while (minNode->leftChild != NULL) {
            minNode = minNode->leftChild;
        }

        node->element->key = minNode->element->key;
        char* tmpValue = node ->element->value;
        node->element->value = minNode->element->value;
        free(tmpValue);

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

        free(node->element->value);
        free(node->element);
        free(node);
    }
}

void menu(Node** root) {
    int answer = -1;
    int addingKey = 0;

    while (answer != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value by key\n2.Get value by key\n3.Check for key availability\n4.Delete key.");
        printf("\nNumber of option: ");
        Scanf(&answer);
        if (answer == 0) {
            break;
        }
        else if (answer == 1) {
            printf("\nWrite the key: ");
            Scanf("%d", &addingKey);
            char* addingValue = calloc(256, sizeof(char));
            printf("\nWrite the key value with less than 20 characters: ");
            getchar();
            fgets(addingValue, 256, stdin);
            add(root, addingKey, addingValue);
        }
        else if (answer == 2 || answer == 3) {
            printf("\nSpecify the key: ");
            Scanf(&addingKey);
            Node* founded = search(*root, addingKey);
            if (founded == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                printf("\nValue: %s", founded->element->value);
            }
        }
        else if (answer == 4) {
            printf("\nSpecify the key: ");
            Scanf(&addingKey);
            if (search(*root, addingKey) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                deleteElement(root, addingKey);
                printf("\nThe value and key have been deleted.");
            }
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }
}
