#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdbool.h>
#include "oddNumberList.h"

typedef struct Element {
    int value;
    struct Element* next;
}Element;

void push(Element** head, int value, bool* errorCode) {
    Element* element = calloc(1, sizeof(Element));
    if (element == NULL) {
        *errorCode = false;
        return;
    }
    element->value = value;
    element->next = *head;
    *head = element;
}

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

Element* createList(void) {
    return NULL;
}

void solution(Element** list, bool* errorCode) {
    int size = 0;
    printf("Enter size of list: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        *errorCode = false;
        return;
    }
    printf("\nEnter elements: ");
    for (int i = 0; i < size; ++i) {
        int number = 0;
        if (scanf("%d", &number) != 1) {
            *errorCode = false;
            return;
        }
        push(list, number, errorCode);
    }

    Element* current = *list;
    Element* previous = NULL;

    while (current != NULL) {
        if (current->value % 2 == 1) {
            if (previous == NULL) {
                pop(list);
                current = *list;
            }
            else {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
        }
        else {
            previous = current;
            current = current->next;
        }
    }

    printf("Remaining elements: ");
    current = *list;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

bool test(void) {
    bool errorCode = true;
    Element* list = NULL;
    push(&list, 1, &errorCode);
    push(&list, 2, &errorCode);
    push(&list, 3, &errorCode);
    while (list != NULL) {
        pop(&list);
    }
    return list == NULL && errorCode == true;
}
