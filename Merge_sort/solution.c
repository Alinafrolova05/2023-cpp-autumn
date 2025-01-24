#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "sort.h"

void fillingTheArray(Number** stack, Number* phone, int size) {
    if (*stack == NULL) return;

    phone[size - 1].name = (*stack)->name;
    phone[size - 1].number = (*stack)->number;

    Number* tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);

    fillingTheArray(stack, phone, size - 1);
}

void sort(void) {
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) { 
        fprintf(stderr, "The file does not open :(\n");
        return;
    }

    Number* stack = NULL;
    int size = 0;
    writeInBuffer(file, &stack, &size);
    fclose(file);

    Number* phone = malloc(size * sizeof(Number));
    if (phone == NULL) {
        printf("Error!");
        return;
    }
    fillingTheArray(&stack, phone, size);


    printf("Before sorting:\n");
    print(phone, size);
    printf("\nSpecify the option number:\n0.Exit\n1.Sort by name\n2.Sort by phone number");
    printf("\nNumber of option: ");

    SortChoice choice = 50;
    while (choice != EXIT) {
        scanfChecker(&choice);
        if (choice == EXIT) {
            break;
        } else if (choice == SORT_BY_NAME || choice == SORT_BY_NUMBER) {
            mergeSort(phone, size, choice);
            printf("\nAfter sorting:\n");
            print(phone, size);
        } else {
            printf("\nInput wrong!");
        }
    }

    for (int i = 0; i < size; i++) {
        free(phone[i].name);
        free(phone[i].number);
    }
}
