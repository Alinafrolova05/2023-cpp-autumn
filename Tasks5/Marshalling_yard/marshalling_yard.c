#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

void push(Element** head, char value) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value;
    element->next = *head;
    *head = element;
}

void pop(Element** head2) {
    Element* tmp = *head2;
    *head2 = (*head2)->next;
    free(tmp);
}

int main()
{
    char str[100] = { 0 };
    printf("Enter numbers and operations: ");
    gets(str, 100, stdin);
    
    Element* numbers = calloc(1, sizeof(Element));
    Element* operations = calloc(1, sizeof(Element));
    Element* pointerNumbers = operations;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(') {
            push(&operations, str[i]);
        }
        else if ((str[i] == '*' || str[i] == '/') && (operations->value == '*' || operations->value == '/')) {
            push(&numbers, operations->value);
            pop(&operations);
            push(&operations, str[i]);
        }
        else if ((str[i] == '*' || str[i] == '/') && (operations->value != '*' || operations->value != '/')) {
            push(&operations, str[i]);
        }
        else if ((str[i] == '+' || str[i] == '-') && (operations != NULL || operations->value != ')')) {
            push(&numbers, operations->value);
            pop(&operations);
            push(&operations, str[i]);
        } 
        else if (str[i] == ')') {
            while (str[i] != '(') {
                push(&numbers, operations->value);
                pop(&operations);
            }
            pop(&operations);
        }
        else {
            push(&numbers, str[i]);
        }
    }

    printf("\nDifferent form: ");
    while (operations != pointerNumbers) {
        printf("%c", operations->value);
        pop(&operations);
    }
    pop(&operations);
    return 0;
}