#include "functions.h"
#include <stdlib.h>

void push(Element** head, char value) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value;
    element->next = *head;
    *head = element;
}

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void print(Element* numbers, Element* pointerOut) {
    char str1[20] = { 0 };
    int i = 0;
    printf("\nDifferent form: ");
    while (numbers != pointerOut) {
        str1[i] = numbers->value;
        pop(&numbers);
        i++;
    }
    while (i >= 0) {
        printf("%c", str1[i]);
        i--;
    }
    pop(&numbers);
}
