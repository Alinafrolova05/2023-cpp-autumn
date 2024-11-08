#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "functions.h"

bool testScanf(int result) {
    return result == 1;
}

void Scanf(int* add) {
    int result = scanf("%d", add);
    if (!testScanf(result)) {
        printf("\nInput wrong!");
        return -1;
    }
}

void addElement(Element** front, int value) {
    Element* element1 = malloc(sizeof(Element));
    while ((*front)->next != NULL || (*front)->value != value) {
        (*front) = (*front)->next;
    }
    element1->value = value;
    if ((*front)->next != NULL) {
        element1->next = (*front)->next;
    }
    (*front)->next = element1;
}

void deleteElement(Element** front, int value) {
    while ((*front)->value != value) {
        if ((*front) == NULL) {
            return;
        }
        (*front) = (*front)->next;
    }
    Element* delete = (*front)->next;
    (*front)->next = (*front)->next->next;
    free(delete);
}

void printList(Element* element1) {
    while (element1 != NULL) {
        printf(" %d", element1->value);
        element1 = element1->next;
    }
    free(element1);
}

void pop(Element* head) {
    Element* tmp = head;
    head = head->next;
    free(tmp);
}
