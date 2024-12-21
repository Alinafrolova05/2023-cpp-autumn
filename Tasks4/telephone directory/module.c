#define _CRT_SECURE_NO_WARNINGS

#include "module.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

void choices(FILE* file, PhoneBook* entry, int size) {
    int answer = 8;
    printf("\nAnswer: ");
    int result = scanf("%d", &answer);

    while (answer != 0) {
        if (answer == 1) {
            printf("name = ");
            int res = scanf("%s", entry[size].name);
            printf("number = ");
            res = scanf("%s", entry[size].number);
            size++;
        }
        else if (answer == 2) {
            printAllFile(file);
        }
        else if (answer == 3) {
            char name[20] = { 0 };
            printf("\nInput name: ");
            int res = scanf("%s", name);
            char buffer[50] = { 0 };
            find(file, name, buffer);
            printf("%s", buffer);
        }
        else if (answer == 4) {
            char number[20] = { 0 };
            printf("\nInput number: ");
            int res = scanf("%s", number);
            char buffer[50] = { 0 };
            find(file, number, buffer);
            printf("%s", buffer);
        }
        else if (answer == 5) {
            printInFile(file, entry, size);
            break;
        }
        else {
            printf("\nInput Error!!!!!");
            break;
        }
        printf("\nNext answer: ");
        result = scanf("%d", &answer);
    }
}

bool test(FILE* file) {
    char buffer[50] = { 0 };
    char name[50] = "rtrt";
    find(file, name, buffer);
    for (int i = 0; i < strlen("rtrt"); ++i) {
        if (buffer[i] != name[i]) {
            return false;
        }
    }
    return true;
}
