#include "stack.h"
#include <stdlib.h>
#include "stdio.h"

typedef struct Stack {
    Tree* element;
    struct Stack* next;
} Stack;

void push(Stack** head, Tree* element, bool* errorCode) {
    Stack* newStackNode = (Stack*)calloc(1, sizeof(Stack));
    if (newStackNode == NULL) {
        *errorCode = false;
        return;
    }
    newStackNode->element = element;
    newStackNode->next = *head;
    *head = newStackNode;
}

Tree* pop(Stack** head) {
    if (*head == NULL) return NULL;
    Stack* tmp = *head;
    Tree* element = tmp->element;
    *head = (*head)->next;
    free(tmp);
    return element;
}
