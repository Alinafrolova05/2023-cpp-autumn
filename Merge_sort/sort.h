#pragma once

#ifndef MERGE_SORT
#define MERGE_SORT

#include <stdbool.h>

typedef struct Number {
    char* name;
    char* number;
    struct Number* next;
} Number;

typedef enum {
    EXIT = 0,
    SORT_BY_NAME = 1,
    SORT_BY_NUMBER = 2,
} SortChoice;

// Checks if choice is an integer.
void scanfChecker(SortChoice* choice);

// Reads data from a file into arrays.
void writeInBuffer(FILE* file, Number** phone, int* n);

// Prints numbers and phone numbers.
void print(Number* phone, int size);

// Merges two arrays into one.
void merge(Number* phone, Number* left, Number* right, int size, SortChoice choice);

// Splits into two arrays.
void mergeSort(Number* phone, int size, SortChoice choice);

// Fills an array with data from the linked list of Number structures.
void fillingTheArray(Number** stack, Number* phone, int size);

// Main function to handle the sorting process based on user input.
void sort(void);

// Test function to verify sorting by name works correctly.
bool testSortByName(void);

// Test function to verify sorting by phone number works correctly.
bool testSortByNumber(void);

#endif
