#pragma once

#include <stdbool.h>

typedef enum {
    EXIT = 0,
    SORT_BY_NAME = 1,
    SORT_BY_NUMBER = 2,
} SortChoice;

// Fills an array with data from the linked list of Number structures.
void fillingTheList(List** stack, List** phoneList);

// Main function to handle the sorting process based on user input.
void sort(void);
