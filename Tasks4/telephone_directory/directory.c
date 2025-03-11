#define _CRT_SECURE_NO_WARNINGS

#include "directory.h"
#include <stdlib.h>
#include <string.h>

typedef struct PhoneBook {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} PhoneBook;

void setName(PhoneBook* entry, int i, char* value) {
    strcpy(entry[i].name, value);
}

void setNumber(PhoneBook* entry, int i, char* value) {
    strcpy(entry[i].number, value);
}

PhoneBook* createPhoneBook(void) {
    return calloc(100, sizeof(PhoneBook));
}

void loadFromFile(char* charFile, PhoneBook* entries, int* size, bool* errorCode) {
    FILE* file = fopen(charFile, "r");
    if (!file) {
        *errorCode = false;
        return;
    }
    while (fscanf(file, "%s %s", entries[*size].name, entries[*size].number) == 2) {
        (*size)++;
        if (*size >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
}

void saveToFile(char* charFile, PhoneBook* entries, int size, bool* errorCode) {
    FILE* file = fopen(charFile, "w");
    if (!file) {
        *errorCode = false;
        return;
    }
    for (int i = 0; i < size; ++i) {
        fprintf(file, "%s %s\n", entries[i].name, entries[i].number);
    }
    fclose(file);
}

void getEntryFromUser(PhoneBook* entry, int i) {
    printf("Enter name: ");
    scanf("%s", entry[i].name);
    printf("Enter number: ");
    scanf("%s", entry[i].number);
}

void printAllEntries(PhoneBook* entries, int size) {
    if (size == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\nPhonebook Records:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. Name: %s, Number: %s\n", i + 1, entries[i].name, entries[i].number);
    }
}

bool find(PhoneBook* entries, char name[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            strcpy(name, entries[i].name);
            return true;
        }
    }
    return false;
}
