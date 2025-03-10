#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "inputOutput.h"
#include "mergeSorting.h"

void fillingTheList(List** stack, List** phoneList) {
    if (*stack == NULL) return;

    List* tmp = *stack;
    *stack = getNextList(*stack);

    List* newNode = createNode(getNumberOfList(tmp));
    List* element = getNextList(newNode);
    element = *phoneList;
    *phoneList = newNode;

    free(tmp);

    fillingTheList(stack, phoneList);
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
    fillingTheList(&stack, &phoneList);

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
