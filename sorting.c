#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "sorting.h"

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
            while (*operations != NULL && getValueOfElement(*operations) != '(') {
                push(numbers, getValueOfElement(*operations), errorCode);
                if (!(*errorCode)) return;
                pop(operations);
            }
            pop(operations);
        }
        else {
            while (*operations != NULL &&
                (getValueOfElement(*operations) == '*' || getValueOfElement(*operations) == '/') &&
                (str[i] == '+' || str[i] == '-')) {
                push(numbers, getValueOfElement(*operations), errorCode);
                if (!(*errorCode)) return;
                pop(operations);
            }
            push(operations, str[i], errorCode);
            if (!(*errorCode)) return;
        }
    }

    while (*operations != NULL) {
        push(numbers, getValueOfElement(*operations), errorCode);
        if (!(*errorCode)) return;
        pop(operations);
    }
}

char* solution(char str[], bool* errorCode) {
    Element* numbers = NULL;
    Element* operations = NULL;

    processInput(str, &numbers, &operations, errorCode);

    char array[256] = {0};
    int i = 0;

    while (numbers != NULL) {
        array[i++] = getValueOfElement(numbers);
        Element* tmp = numbers;
        numbers = getNextElement(numbers);
        free(tmp);
    }

    char* isCorrect = (char*)calloc(256, sizeof(char));
    for (int j = 0; j < i; ++j) {
        isCorrect[j] = array[i - j - 1];
    }

    while (operations != NULL) {
        Element* tmp = operations;
        operations = getNextElement(operations);
        free(tmp);
    }

    return isCorrect;
}
