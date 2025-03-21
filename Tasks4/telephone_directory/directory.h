#pragma once

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 50

#include <stdio.h>
#include <stdbool.h>

// Defines the structure.
typedef struct PhoneBook PhoneBook;

// Creates structure.
PhoneBook* createPhoneBook(void);

// Sets name.
void setName(PhoneBook* entry, int i, char* value);

// Sets number.
void setNumber(PhoneBook* entry, int i, char* value);

// Writes a new number.
void getEntryFromUser(PhoneBook* entry, int i);

// Displays all numbers.
void printAllEntries(PhoneBook* entries, int size);

// Loads data from a file into a structure.
void loadFromFile(char* charFile, PhoneBook* entries, int* size, bool* errorCode);

// Writes the number to a file.
void saveToFile(char* charFile, PhoneBook* entries, int size, bool* errorCode);

// Finds the recorded number.
bool find(PhoneBook* entries, char name[], int size);
