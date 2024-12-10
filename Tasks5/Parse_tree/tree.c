#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void push(Stack** head, Element* element) {
    Stack* newStackNode = (Stack*)calloc(1, sizeof(Stack));
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

void count(Element* element) {
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
}

int precedence(char value) {
    if (value == '+' || value == '-') return 1;
    if (value == '*' || value == '/') return 2;
    return 0;
}

void tree(char* str, Stack** numberStack, Stack** operationStack) {
    for (int i = 0; str[i] != '\0'; ++i) {
        char currentChar = str[i];

        if (isspace(currentChar)) {
            continue;
        }

        if (isdigit(currentChar)) {
            Element* newNode = (Element*)calloc(1, sizeof(Element));
            newNode->value = currentChar;
            newNode->result = currentChar - '0';
            push(numberStack, newNode);
        }
        else if (currentChar == '(') {
            Element* newNode = (Element*)calloc(1, sizeof(Element));
            newNode->value = currentChar;
            push(operationStack, newNode);
        }
        else if (currentChar == ')') {
            while (*operationStack != NULL && (*operationStack)->element->value != '(') {
                Element* operatorNode = pop(operationStack);
                operatorNode->rightChild = pop(numberStack);
                operatorNode->leftChild = pop(numberStack);
                push(numberStack, operatorNode);
            }
            pop(operationStack);
        }
        else {
            while (*operationStack != NULL && precedence((*operationStack)->element->value) >= precedence(currentChar)) {
                Element* operatorNode = pop(operationStack);
                operatorNode->rightChild = pop(numberStack);
                operatorNode->leftChild = pop(numberStack);
                push(numberStack, operatorNode);
            }
            Element* newNode = (Element*)calloc(1, sizeof(Element));
            newNode->value = currentChar;
            push(operationStack, newNode);
        }
    }

    while (*operationStack != NULL) {
        Element* operatorNode = pop(operationStack);
        operatorNode->rightChild = pop(numberStack);
        operatorNode->leftChild = pop(numberStack);
        push(numberStack, operatorNode);
    }
}
