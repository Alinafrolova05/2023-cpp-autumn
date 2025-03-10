#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "balance.h"
#include "stack.h"

bool processBraces(const char* str) {
    Stack* stack = NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
            if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
                if (stack != NULL) {
                    char lastBrace = top(stack);
                    if ((str[i] == ')' && lastBrace == '(') ||
                        (str[i] == '}' && lastBrace == '{') ||
                        (str[i] == ']' && lastBrace == '[')) {
                        pop(&stack);
                    } else {
                        while (stack != NULL) {
                            pop(&stack);
                        }
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                bool errorCode = true;
                push(&stack, str[i], &errorCode);
                if (!errorCode) {
                    while (stack != NULL) {
                        pop(&stack);
                    }
                    return false;
                }
            }
        }
    }
    if (stack != NULL) {
        while (stack != NULL) {
            pop(&stack);
        }
        return false;
    }
    return true;
}
