#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    char str[100] = { 0 };
    printf("Enter numbers and operations: ");
    gets(str, 100, stdin);
    
    Element* numbers = calloc(1, sizeof(Element));
    Element* pointerOut = numbers;
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
        else if ((str[i] == '*' || str[i] == '/') && (operations->value != '*' && operations->value != '/')) {
            push(&operations, str[i]);
        }
        else if ((str[i] == '+' || str[i] == '-') && (operations != NULL && operations->value != ')' && operations->value != '(')) {
            push(&numbers, operations->value);
            pop(&operations);
            push(&operations, str[i]);
        }
        else if ((str[i] == '+' || str[i] == '-') && !(operations != NULL && operations->value != ')' && operations->value != '(')) {
            push(&operations, str[i]);
        }
        else if (str[i] == ')') {
            while (operations->value != '(') {
                push(&numbers, operations->value);
                pop(&operations);
            }
            pop(&operations);
        }
        else {
            push(&numbers, str[i]);
        }
    }
    while (operations != pointerNumbers) {
        push(&numbers, operations->value);
        pop(&operations);
    }
    pop(&operations);

    print(numbers, pointerOut);
    return 0;
}
