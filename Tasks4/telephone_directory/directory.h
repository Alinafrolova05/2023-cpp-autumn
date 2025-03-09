#pragma once

#include <stdio.h>
#include <stdbool.h>

// Defines the structure.
typedef struct PhoneBook PhoneBook;

// Creates structure.
PhoneBook* createPhoneBook(void);

// Returns the name from the structure.
char* getName(PhoneBook* entry, int i);

// Returns the number from the structure.
char* getNumber(PhoneBook* entry, int i);

//Writes a new number
void write(PhoneBook* entry, int size);

//Displays all numbers
void printAllFile(FILE* file);

//Writes the number to a file
void printInFile(FILE* file, PhoneBook* entry, int size);

//Finds the recorded number
void find(FILE* file, char* name, char* buffer);
