#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

typedef struct Tree {
    char value;
    int result;
    struct Tree* leftChild;
    struct Tree* rightChild;
} Tree;

void freeTree(Tree** element) {
    if (*element == NULL) return;
    freeTree(&((*element)->leftChild));
    freeTree((&(*element)->rightChild));
    free(*element);
}

Tree* createNode(char value, bool* errorCode) {
    Tree* newNode = (Tree*)calloc(1, sizeof(Tree));
    if (newNode == NULL) {
        *errorCode = false;
        return NULL;
    }
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Tree* tree(char* str, bool* errorCode) {
    Stack* stream = NULL;
    int size = strlen(str);
    for (int i = size - 1; i >= 0; --i) {
        char currentChar = str[i];
        if (isspace(currentChar)) {
            continue;
        }
        if (isdigit(currentChar)) {
            Tree* newNode = createNode(currentChar, errorCode);
            if (!*errorCode) {
                return NULL;
            }
            newNode->result = currentChar - '0';
            push(&stream, newNode, errorCode);
            if (!*errorCode) {
                return NULL;
            }
        }
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            Tree* operatorNode = createNode(currentChar, errorCode);
            if (!*errorCode) {
                return NULL;
            }
            operatorNode->leftChild = pop(&stream);
            operatorNode->rightChild = pop(&stream);
            push(&stream, operatorNode, errorCode);
            if (!*errorCode) {
                return NULL;
            }
        }
    }
    return pop(&stream);
}

void printTree(Tree* element) {
    if (element == NULL) return;
    if (element->leftChild != NULL || element->rightChild != NULL) {
        printf("(");
    }
    printf("%c", element->value);
    printTree(element->leftChild);
    printTree(element->rightChild);
    if (element->leftChild != NULL || element->rightChild != NULL) {
        printf(")");
    }
}

int count(Tree* element, bool* errorCode) {
    if (element == NULL) return 0;

    count(element->leftChild, errorCode);
    count(element->rightChild, errorCode);
    if (element->value == '+') { 
        element->result = element->leftChild->result + element->rightChild->result;
    }
    else if (element->value == '-') {
        element->result = element->leftChild->result - element->rightChild->result;
    }
    else if (element->value == '*') {
        element->result = element->leftChild->result * element->rightChild->result;
    }
    else if (element->value == '/') {
        if (element->rightChild->result != 0) {
            element->result = element->leftChild->result / element->rightChild->result;
        }
        else {
            *errorCode = false;
            return -1;
        }
    }
    return element->result;
}

int countResult(char* str, bool* errorCode) {
    Tree* element = tree(str, errorCode);
    return count(element, errorCode);
}
