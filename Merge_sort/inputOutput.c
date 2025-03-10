#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sort.h"
#include "mergeSorting.h"

typedef struct Number {
    char* name;
    char* number;
    struct Number* next;
} Number;

Number* createNumber() {
    return calloc(1, sizeof(Number));
}

char* getName(Number* number) {
    return number->name;
}

char* getNumber(Number* number) {
    return number->number;
}

void toCheckScanf(SortChoice* choice) {
    while (true) {
        printf("Please enter your choice (%d for exit, %d for name, %d for number): ", EXIT, SORT_BY_NAME, SORT_BY_NUMBER);
        int result = scanf("%d", choice);
        if (result != 1 || *choice < EXIT || *choice > SORT_BY_NUMBER) {
            printf("\nInput wrong! Please enter a valid number: ");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    }
}

void writeInBuffer(FILE* file, List** phoneList) {
    while (!feof(file)) {
        char array[256] = { '\0' };
        if (fgets(array, 256, file) != NULL) {
            Number element;
            char* arrayForName = calloc(256, sizeof(char));
            char* arrayForNumber = calloc(256, sizeof(char));
            int i = 0;
            while (array[i] != '-' && array[i] != '\0') {
                arrayForName[i] = array[i];
                i++;
            }
            i++;
            int j = 0;
            while (array[i] != '\0') {
                arrayForNumber[j] = array[i];
                i++;
                j++;
            }

            strcpy(element.name, arrayForName);
            strcpy(element.number, arrayForNumber);
            free(arrayForName);
            free(arrayForNumber);

            List* newNode = createNode(element);
            List* current = getNextList(newNode);
            current = *phoneList;
            *phoneList = newNode;
        }
    }
}

void printList(List* node) {
    while (node != NULL) {
        Number* element = getNumberOfList(node);
        printf("Name: %s, Number: %s\n", element->name, element->number);
        node = getNextList(node);
    }
}
