#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

typedef struct Element {
    char value;
    int result;
    struct Element* leftChild;
    struct Element* rightChild;
} Element;

typedef struct Stack {
    Element* element;
    struct Stack* next;
} Stack;

void freeTree(Element* element) {
    if (element == NULL) return;
    freeTree(element->leftChild);
    freeTree(element->rightChild);
    free(element);
}

void push(Stack** head, Element* element) {
    Stack* newStackNode = (Stack*)calloc(1, sizeof(Stack));
    if (newStackNode == NULL) {
        return;
    }
    newStackNode->element = element;
    newStackNode->next = *head;
    *head = newStackNode;
}

Element* pop(Stack** head) {
    if (*head == NULL) return NULL;
    Stack* tmp = *head;
    Element* element = tmp->element;
    *head = (*head)->next;
    free(tmp);
    return element;
}

void print(Element* element) {
    if (element == NULL) return;
    if (element->leftChild != NULL || element->rightChild != NULL) {
        printf("(");
    }
    printf("%c", element->value);
    print(element->leftChild);
    print(element->rightChild);
    if (element->leftChild != NULL || element->rightChild != NULL) {
        printf(")");
    }
}

int count(Element* element) {
    if (element == NULL) return;

    count(element->leftChild);
    count(element->rightChild);
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
            printf("Error!\n");
            exit(EXIT_FAILURE);
        }
    }
    return element->result;
}

Stack* tree(char* str) {
    Stack* stream = NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        char currentChar = str[i];
        if (isspace(currentChar)) {
            continue;
        }
        if (isdigit(currentChar)) {
            Element* newNode = (Element*)calloc(1, sizeof(Element));
            newNode->value = currentChar;
            newNode->result = currentChar - '0';
            push(&stream, newNode);
        } else if (currentChar == '(') {
            Element* newNode = (Element*)calloc(1, sizeof(Element));
            newNode->value = currentChar;
            push(&stream, newNode);
        } else if (currentChar == ')') {
            while (stream != NULL && stream->element->value != '(') {
                Element* leftChild = pop(&stream);
                Element* rightChild = pop(&stream);
                Element* operatorNode = pop(&stream);
                
                operatorNode->leftChild = leftChild;
                operatorNode->rightChild = rightChild;

                push(&stream, operatorNode);
            }
        }
    }
    return stream;
}

void printTree(char* str) {
    Stack* stream = tree(str);
    Stack* stack = NULL;
    Element* current = stream != NULL ? pop(&stream) : NULL;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->leftChild;
        }
        if (stack != NULL) {
            current = pop(&stack);
            printf("%c ", current->value);
            current = current->rightChild;
        }
    }
}

int resultOfCounting(char* str) {
    printTree(str);
    Stack* treeStack = tree(str);
    Element* element = pop(&treeStack);
    return count(element);
}
