#include "stack.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct Element {
    char value;
    struct Element* next;
}Element;

bool test(void) {
    bool errorCode = true;
    Element* stack = NULL;

    if (stack != NULL) {
        errorCode = false;
        return errorCode;
    }

    push(&stack, 'A', &errorCode);
    if (!errorCode) {
        return errorCode;
    }

    push(&stack, 'B', &errorCode);
    if (!errorCode) {
        return errorCode;
    }

    push(&stack, 'C', &errorCode);
    if (!errorCode) {
        return errorCode;
    }

    pop(&stack);
    if (stack->value != 'B') {
        errorCode = false;
        return errorCode;
    }

    pop(&stack);
    if (stack ->value != 'A') {
        errorCode = false;
        return errorCode;
    }

    pop(&stack);
    if (stack != NULL) {
        errorCode = false;
        return errorCode;
    }

    return errorCode;
}
