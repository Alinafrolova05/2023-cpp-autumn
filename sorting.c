#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct Element {
    char value;
    struct Element* next;
} Element;

void processInput(char* str, Element** numbers, Element** operations, bool* errorCode) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isspace(str[i])) {
            continue;
        }
        if (isdigit(str[i])) {
            while (isdigit(str[i])) {
                push(numbers, str[i], errorCode);
                if (!(*errorCode)) return;
                i++;
            }
            i--;
        }
        else if (str[i] == '(') {
            push(operations, str[i], errorCode);
            if (!(*errorCode)) return;
        }
        else if (str[i] == ')') {
            while (*operations != NULL && (*operations)->value != '(') {
                push(numbers, (*operations)->value, errorCode);
                if (!(*errorCode)) return;
                pop(operations);
            }
            pop(operations);
        }
        else {
            while (*operations != NULL &&
                ((*operations)->value == '*' || (*operations)->value == '/') &&
                (str[i] == '+' || str[i] == '-')) {
                push(numbers, (*operations)->value, errorCode);
                if (!(*errorCode)) return;
                pop(operations);
            }
            push(operations, str[i], errorCode);
            if (!(*errorCode)) return;
        }
    }

    while (*operations != NULL) {
        push(numbers, (*operations)->value, errorCode);
        if (!(*errorCode)) return;
        pop(operations);
    }
}

bool test(void) {
    bool errorCode = true;
    char str[20] = "(2+2)/9";
    char correct[20] = "22+9/";
    Element* numbers = NULL;
    Element* operations = NULL;

    processInput(str, &numbers, &operations, &errorCode);

    char array[20] = { 0 };
    int i = 0;

    while (numbers != NULL) {
        array[i++] = numbers->value;
        Element* tmp = numbers;
        numbers = numbers->next;
        free(tmp);
    }

    char isCorrect[20] = { 0 };
    for (int j = 0; j < i; ++j) {
        isCorrect[j] = array[i - j - 1];
    }

    while (operations != NULL) {
        Element* tmp = operations;
        operations = operations->next;
        free(tmp);
    }

    return strcmp(correct, isCorrect) == 0 && errorCode == true;
}
