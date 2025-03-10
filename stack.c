#include "stack.h"
#include "balance.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    char value;
    struct Stack* next;
} Stack;

char top(Stack* element) {
    return element->value;
}

void push(Stack** head, char value, bool* errorCode) {
    Stack* element = calloc(1, sizeof(Stack));
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
