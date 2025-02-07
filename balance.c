#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "balance.h"
#include "stack.h"

typedef struct Element {
    char value;
    struct Element* next;
} Element;

Element* createElement(void) {
    return malloc(sizeof(Element));
}

char top(Element* element) {
    return element->value;
}

void setTop(Element** element, char value) {
    (*element)->value = value;
}

void setToNextElement(Element** element, Element* next) {
    (*element)->next = next;
}

void setNextElement(Element** element, Element* anotherElement) {
    *element = anotherElement->next;
}

void popStack(Element* stack, char check[]) {
    int i = 0;
    while (stack != NULL) {
        check[i] = top(stack);
        i++;
        pop(&stack);
    }
}

void processBraces(char* str, bool* errorCode, char check[]) {
    Element* stack = NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
            if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
                if (stack != NULL) {
                    char lastBrace = stack->value;
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
