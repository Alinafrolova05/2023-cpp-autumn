#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

void push(Element** head, int value) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value;
    element->next = *head;
    *head = element;
}

void pop(Element** head2) {
    Element* tmp = *head2;
    *head2 = (*head2)->next;
    free(tmp);
}

void operation(Element* element1, char str[], int i, int* answer) {
    if (str[i] == '+') {
        element1->next->value += element1->value;
    }
    if (str[i] == '-') {
        element1->next->value -= element1->value;
    }
    if (str[i] == '/') {
        if (element1->value == 0) {
            printf("\nError!!!");
            return;
        }
        element1->next->value /= element1->value;
    }
    if (str[i] == '*') {
        element1->next->value *= element1->value;
    }
    *answer = element1->next->value;
}

void numbers(Element* element1, char str[], int* answer) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            operation(element1, str, i, answer);
            pop(&element1);
        }
        else {
            int number = (int)(str[i]) - 48;
            push(&element1, number);
        }
    }
}

bool test(Element* element1, int answer) {
    char str[20] = "96-12+*";
    numbers(element1, str, &answer);
    return answer == 9;
}
