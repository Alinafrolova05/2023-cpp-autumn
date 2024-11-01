#include "module.h"
#include <stdbool.h>
#include <stdio.h>

bool testFile(FILE* file) {
    return file != NULL;
}

void fillArray(FILE* file1, char str[]) {
    while (!feof(file1)) {
        char* res = fgets(str, 100, file1);
        if (res == NULL) {
            break;
        }
    }
}

void printInFile(FILE* file2, char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        int k = 1;
        while (str[i] == str[i + k]) {
            k++;
        }
        fprintf(file2, "%c", str[i]);
        i += k;
    }
}
