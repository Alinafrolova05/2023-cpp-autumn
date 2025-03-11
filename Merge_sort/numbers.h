#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct Number Number;

// Creates number.
Number* createNumber();

// Returns name from number.
char* getName(Number* number);

// Writes down the number name.
void setName(Number* number, char* name);

// Returns number from number.
char* getNumber(Number* number);

// Writes down the number.
void setNumber(Number* number, char* num);

// Returns the next number.
Number* getNextNumber(Number* number);

// Duplicate a string and return a pointer to the new copy.
char* myStrdup(char* str, bool* errorCode);

// Frees the number.
void freeNumber(Number** number);
