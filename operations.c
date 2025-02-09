#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "operations.h"
#include "stack.h"

int performOperation(char str, int operand1, int operand2, bool* errorCode) {
    if (str == '+') {
        return operand1 + operand2;
    }
    if (str == '-') {
        return operand1 - operand2;
    }
    if (str == '/') {
        if (operand2 == 0) {
            *errorCode = false;
            return 0;
        }
        return operand1 / operand2;
    }
    if (str == '*') {
        return operand1 * operand2;
    }
    *errorCode = false;
    return 0;
}

int processNumbers(Element** element, bool* errorCode) {
    if (*element == NULL) {
        return 0;
    }

    char operatorChar = top(*element);
    pop(element);

    if (!(operatorChar == '+' || operatorChar == '-' || operatorChar == '/' || operatorChar == '*')) {
        *errorCode = false;
        return 0;
    }

    int operand1 = 0;
    int operand2 = 0;

    if (*element != NULL) {
        char operandChar1 = top(*element);
        if (operandChar1 == '+' || operandChar1 == '-' || operandChar1 == '/' || operandChar1 == '*') {
            operand1 = processNumbers(element, errorCode);
        }
        else {
            operand1 = operandChar1 - '0'; 
            pop(element);
        }
    }

    if (*element != NULL) {
        char operandChar2 = top(*element);
        if (operandChar2 == '+' || operandChar2 == '-' || operandChar2 == '/' || operandChar2 == '*') {
            operand2 = processNumbers(element, errorCode);
        }
        else {
            operand2 = operandChar2 - '0';
            pop(element);
        }
    }

    return performOperation(operatorChar, operand2, operand1, errorCode);
}

int solution(char str[], bool* errorCode) {
    int size = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        size++;
    }
    Element* element = NULL;
    for (int i = 0; i < size; ++i) {
        push(&element, str[i], errorCode);
        if (!*errorCode) {
            return 0;
        }
    }
    return processNumbers(&element, errorCode);
}
