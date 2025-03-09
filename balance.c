#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "balance.h"
#include "stack.h"

void processBraces(char* str, bool* errorCode, char check[]) {
    Element* stack = NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
            if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
                if (stack != NULL) {
                    char lastBrace = top(stack);
                    if ((str[i] == ')' && lastBrace == '(') ||
                        (str[i] == '}' && lastBrace == '{') ||
                        (str[i] == ']' && lastBrace == '[')) {
                        pop(&stack);
                    }
                    else {
                        push(&stack, str[i], errorCode);
                    }
                }
                else {
                    push(&stack, str[i], errorCode);
                }
            }
            else {
                push(&stack, str[i], errorCode);
            }
        }
    }
    popStack(stack, check);
}

char* solution(char str[], bool* errorCode) {
    char* answerSting = (char*)calloc(256, sizeof(char));
    if (answerSting == NULL) {
        *errorCode = false;
        return NULL;
    }
    processBraces(str, errorCode, answerSting);
    if (!*errorCode) {
        return NULL;
    }
    return answerSting;
}
