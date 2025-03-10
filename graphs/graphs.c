#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "solution.h"
#include "test.h"

int main(void) {
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("File doesn't open!!!");
        return -1;
    }

    int numberOfStates = 0;
    bool errorCode = true;
    Table* states = fillOutTable(file, &numberOfStates, &errorCode);
    if (!errorCode) {
        printf("Error!!!");
    }
    else {
        printTable(states, numberOfStates);
    }
    deleteTable(&states, numberOfStates);

    fclose(file);
    return 0;
}
