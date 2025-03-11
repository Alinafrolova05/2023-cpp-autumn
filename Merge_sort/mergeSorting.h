#pragma once

#include "numbers.h"

typedef enum {
    EXIT = 0,
    SORT_BY_NAME = 1,
    SORT_BY_NUMBER = 2,
} SortChoice;

// Defines the structure.
typedef struct List List;

// Frees the list
void freeList(List** phoneList);

// Returns the next element of the list.
List* getNextList(List* list);

// Returns the list element number.
Number* getNumberOfList(List* list);

// Adds a new element to the list
void push(List** head, Number* number);

// Removes the last element from the list.
Number* pop(List** head);

// Sorts the list.
void mergeSort(List** element, SortChoice choice);
