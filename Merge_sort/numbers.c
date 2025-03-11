#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mergeSorting.h"

typedef struct Number {
    char* name;
    char* number;
    struct Number* next;
} Number;

Number* createNumber() {
    Number* newNumber = calloc(1, sizeof(Number));
    newNumber->name = (char*)calloc(256, sizeof(char));
    newNumber->number = (char*)calloc(256, sizeof(char));
    return newNumber;
}

char* getName(Number* number) {
    return number->name;
}

void setName(Number* number, char* name) {
    number->name = name;
}

char* getNumber(Number* number) {
    return number->number;
}

void setNumber(Number* number, char* num) {
    number->number = num;
}

Number* getNextNumber(Number* number) {
    return number->next;
}

char* myStrdup(char* str, bool* errorCode) {
    if (str == NULL) return NULL;
    size_t len = strlen(str) + 1;
    char* copy = malloc(len);
    if (copy) {
        strcpy(copy, str);
    }
    else {
        *errorCode = false;
    }
    return copy;
}

void freeNumber(Number** number) {
    free((*number)->name);
    free((*number)->number);
    free(*number);
}
