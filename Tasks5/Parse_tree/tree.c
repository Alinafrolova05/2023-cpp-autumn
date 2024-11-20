#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void push(Element** head, char value1) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value1;
    element->next = *head;
    element->next1 = NULL;
    element->next2 = NULL;
    *head = element;
}

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void print(Element* numbers) {
    if (numbers->next == NULL || numbers->next1 == NULL || numbers->next2 == NULL) {
        return;
    }
    printf("%c ", numbers->value);
    print(numbers->next1);
    print(numbers->next2);
}
