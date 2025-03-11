#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergeSorting.h"

typedef struct List {
    Number* element;
    struct List* next;
} List;

List* getNextList(List* list) {
    return list->next;
}

Number* getNumberOfList(List* list) {
    return list->element;
}

List* createNode(Number* element) {
    List* newNode = (List*)malloc(sizeof(List));
    newNode->element = element;
    newNode->next = NULL;
    return newNode;
}

void push(List** head, Number* number) {
    List* newNode = (List*)malloc(sizeof(List));
    if (newNode == NULL) {
        return;
    }
    newNode->element = number;
    newNode->next = *head;
    *head = newNode;
}

Number* pop(List** head) {
    if (*head == NULL) {
        return NULL;
    }

    List* temp = *head;
    Number* deletedNumber = temp->element;
    *head = (*head)->next;
    free(temp);

    return deletedNumber;
}

void freeList(List** phoneList) {
    while (*phoneList != NULL) {
        List* temp = *phoneList;
        *phoneList = (*phoneList)->next;
        freeNumber(&(temp->element));
        free(temp);
    }
}

List* merge(List* left, List* right, SortChoice choice) {
    List* result = NULL;

    if (!left) return right;
    if (!right) return left;

    if ((choice == SORT_BY_NAME && strcmp(getName(left->element), getName(right->element)) <= 0) ||
        (choice == SORT_BY_NUMBER && strcmp(getNumber(left->element), getNumber(right->element)) <= 0)) {
        result = left;
        result->next = merge(left->next, right, choice);
    }
    else {
        result = right;
        result->next = merge(left, right->next, choice);
    }
    return result;
}

void split(List* source, List** left, List** right) {
    List* slow = source;
    List* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

void mergeSort(List** element, SortChoice choice) {
    List* head = *element;
    List* left = NULL;
    List* right = NULL;

    if (!head || !head->next) {
        return;
    }

    split(head, &left, &right);
    mergeSort(&left, choice);
    mergeSort(&right, choice);
    *element = merge(left, right, choice);
}
