#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
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

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void addElement(Element** head, Element* pointer, int value1) {
    Element* element1 = calloc(1, sizeof(Element));
    element1->value = value1;
    if ((*head) == pointer || (*head)->value <= value1) {
        element1->next = *head;
        *head = element1;
        return;
    }

    Element* pointer1 = *head;
    while ((*head)->next != pointer && (*head)->next->value >= value1) {
        *head = (*head)->next;
    }
    element1->next = (*head)->next;
    (*head)->next = element1;
    *head = pointer1;
}

void deleteElement(Element* head, Element* pointer, int value1) {
    if (head == pointer || head->value < value1) {
        return;
    }
    Element* pointer1 = head;
    while (head->next->value != value1) {
        if (head->next == pointer || head->next->value < value1) {
            head = pointer1;
            return;
        }
        head = head->next;
    }
    Element* deleting = head->next;
    head->next = head->next->next;
    free(deleting);
    head = pointer1;
}

void printList(Element* element1, Element* pointer) {
    Element* pointer1 = element1;
    while (element1 != pointer) {
        printf(" %d", element1->value);
        element1 = element1->next;
    }
    element1 = pointer1;
}