#pragma once

#ifndef SORTED_LIST
#define SORTED_LIST

#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element* next;

} Element;

struct List;

// Prompts the user to enter a number and verifies the input for validity.
void scanfChecker(int* add);

// Adds a new element with the specified value to the stack (linked list).
void addElement(Element** head, int value, bool* errorCode);

// Deletes an element with the specified value from the stack (linked list).
void deleteElement(Element* head, int value);

// Prints the elements of the stack (linked list) in order.
void printList(Element* element1);

// Removes the top element from the stack (linked list).
void pop(Element** head);

// Displays a menu for user interaction with the stack operations.
void menu(Element** element);

// Frees the memory allocated for the entire stack (linked list).
void freeList(Element** element);

// Runs a test to verify the functionality of the stack operations.
bool test();

#endif
