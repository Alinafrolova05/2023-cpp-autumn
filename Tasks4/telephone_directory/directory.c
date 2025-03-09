#define _CRT_SECURE_NO_WARNINGS

#include "directory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct PhoneBook {
    char name[12];
    char number[14];
}PhoneBook;

char* getName(PhoneBook* entry, int i) {
    return entry[i].name;
}

char* getNumber(PhoneBook* entry, int i) {
    return entry[i].number;
}

PhoneBook* createPhoneBook(void) {
    return calloc(100, sizeof(PhoneBook));
}

void write(PhoneBook* entry, int size) {
    printf("name = ");
    int result = scanf("%s", entry[size].name);
    printf("number = ");
    result = scanf("%s", entry[size].number);
    size++;
}

void printAllFile(FILE* file) {
    char line[50] = { 0 };
    rewind(file);
    while (fgets(line, 50, file) != NULL) {
        printf("%s", line);
    }
    if (!file) {
        printf("Error reading file!");
    }
}

void printInFile(FILE* file, PhoneBook* entry, int size) {
    for (int i = 0; i < size; ++i) {
        fprintf(file, "\n%s - %s", entry[i].name, entry[i].number);
    }
}

void find(FILE* file, char* name, char* buffer) {
    char line[50] = { 0 };
    rewind(file);
    int count = 0;
    int find = 0;
    while (fgets(line, 50, file) != NULL) {
        for (int i = 0; i < strlen(line) - strlen(name); ++i) {
            count = 0;
            for (int j = 0; j < strlen(name); ++j) {
                if (name[j] != line[i + j]) {
                    count++;
                }
            }
            if (count == 0) {
                break;
            }
        }
        if (count == 0) {
            for (int k = 0; k < strlen(line); ++k) {
                buffer[k] = line[k];
            }
            find = 1;
            break;
        }
    }
    if (find == 0) {
        printf("\nThis name was not found.");
    }
}
