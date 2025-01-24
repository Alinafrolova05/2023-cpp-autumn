#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

void scanfChecker(SortChoice* choice) {
    while (true) {
        printf("Please enter your choice (%d for exit, %d for name, %d for number): ", EXIT, SORT_BY_NAME, SORT_BY_NUMBER);
        int result = scanf("%d", choice);
        if (result != 1  || *choice < EXIT || *choice > SORT_BY_NUMBER) {
            printf("\nInput wrong! Please enter a valid number: ");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    }
}

void writeInBuffer(FILE* file, Number** phone, int* size) {
    while (!feof(file)) {
        char array[256] = { '\0' };
        if (fgets(array, 256, file) != NULL) {
            Number* element = calloc(1, sizeof(Number));
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
            element->name = arrayForName;
            element->number = arrayForNumber;
            element->next = *phone;
            *phone = element;
            (*size)++;
        }
    }
}

void print(Number* phone, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s%s", phone[i].name, phone[i].number);
    }
}
