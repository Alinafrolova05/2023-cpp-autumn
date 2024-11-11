#define _CRT_SECURE_NO_WARNINGS

#include "module.h"
#include <stdio.h>


bool testScanf(int result) {
    return result == 1;
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
    if (fgets(line, 50, file) == NULL) {
        printf("File is empty.");
    }
    else {
        while (!feof(file)) {
            if (fgets(line, 50, file) != NULL);
            printf("%s", line);
        }
    }
}

void printFile(FILE* file, PhoneBook* entry, int size) {
    for (int i = 0; i < size; ++i) {
        fprintf(file, "%s - ", entry[i].name);
        fprintf(file, "%s", entry[i].number);
        fprintf(file, "\n");
    }
}

void find(FILE* file, char* name) {
    char line[50] = { 0 };
    int count = 0;
    int find = 0;
    while (!feof(file)) {
        if (fgets(line, 50, file) != NULL) {
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
                printf("\n%s", line);
                find = 1;
                break;
            }
        }
    }
    if (find == 0) {
        printf("\nThis name was not found.");
    }
}
