#include <stdio.h>
#include <ctype.h>
#include "operations.h"
#include "stack.h"

void freeStack(Stack** stack) {
    while (*stack != NULL) {
        pop(stack);
    }
    free(*stack);
    *stack = NULL;
}

int performOperation(char operatorChar, int operand1, int operand2, bool* errorCode) {
    switch (operatorChar) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            *errorCode = false;
            return 0;
        }
        return operand1 / operand2;
    default:
        *errorCode = false;
        return 0;
    }
}

int processExpression(char str[], bool* errorCode) {
    Stack* operandStack = NULL;

    for (int i = 0; str[i] != '\0'; ++i) {
        char currentChar = str[i];

        if (isdigit(currentChar)) {
            push(&operandStack, currentChar - '0', errorCode);
            if (!*errorCode) {
                freeStack(&operandStack);
                return 0;
            }
        }
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            if (operandStack == NULL) {
                *errorCode = false;
                freeStack(&operandStack);
                return 0;
            }
            int operand2 = top(operandStack);
            pop(&operandStack);
            if (operandStack == NULL) {
                *errorCode = false;
                freeStack(&operandStack);
                return 0;
            }
            int operand1 = top(operandStack);
            pop(&operandStack);

            int result = performOperation(currentChar, operand1, operand2, errorCode);
            if (!*errorCode) {
                freeStack(&operandStack);
                return 0;
            }

            push(&operandStack, result, errorCode);
            if (!*errorCode) {
                freeStack(&operandStack);
                return 0;
            }
        }
    }

    if (operandStack == NULL || getNextElement(operandStack) != NULL) {
        *errorCode = false;
        freeStack(&operandStack);
        return 0;
    }

    int finalResult = top(operandStack);
    freeStack(&operandStack);
    return finalResult;
}

int solution(char str[], bool* errorCode) {
    return processExpression(str, errorCode);
}
