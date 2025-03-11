#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inputOutput.h"
#include "mergeSorting.h"
#include "test.h"

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

void fillTheList(List** stack, List** phoneList) {
    while (*stack != NULL) {
        Number* number = pop(stack);
        if (number != NULL) {
            push(phoneList, number);
        }
    }
}

void sort(void) {
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "The file does not open :(\n");
        return;
    }

    List* stack = NULL;
    writeInBuffer(file, &stack);
    fclose(file);

    List* phoneList = NULL;
    fillTheList(&stack, &phoneList);

    printf("Before sorting:\n");
    printList(phoneList);
    printf("\nSpecify the option number:\n0.Exit\n1.Sort by name\n2.Sort by phone number");
    printf("\nNumber of option: ");

    SortChoice choice = 50;
    while (choice != EXIT) {
        toCheckScanf(&choice);
        if (choice == EXIT) {
            break;
        }
        else if (choice == SORT_BY_NAME || choice == SORT_BY_NUMBER) {
            mergeSort(&phoneList, choice);
            printf("\nAfter sorting:\n");
            printList(phoneList);
        }
        else {
            printf("\nInput wrong!");
        }
    }

    freeList(&phoneList);
}

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    sort();
    return 0;
}
