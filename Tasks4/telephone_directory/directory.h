#ifndef TELEPHONE

#include <stdio.h>
#include <stdbool.h>

typedef struct PhoneBook {
    char name[12];
    char number[14];
}PhoneBook;

void write(PhoneBook* entry, int size);
//writes a new number

void printAllFile(FILE* file);
//displays all numbers

void printInFile(FILE* file, PhoneBook* entry, int size);
//writes the number to a file

void find(FILE* file, char* name, char* buffer);
//finds the recorded number

void choices(FILE* file, PhoneBook* entry, int size);
//this is the options

bool test(FILE* file);

#endif