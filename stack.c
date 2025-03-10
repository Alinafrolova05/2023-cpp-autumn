#include "stack.h"
#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    char value;
    struct Stack* next;
} Stack;

Stack* createElement(void) {
    return calloc(1, sizeof(Stack));
}

char top(Stack* element) {
    return element->value;
}

Stack* getNextElement(Stack* element) {
    return element->next;
}

void push(Stack** head, char value, bool* errorCode) {
    Stack* element = createElement();
    if (element == NULL) {
        *errorCode = false;
        return;
    }
    element->value = value;
    element->next = *head;
    *head = element;
}

void pop(Stack** element) {
    if (*element == NULL) return;
    Stack* tmp = *element;
    *element = (*element)->next;
    free(tmp);
}
