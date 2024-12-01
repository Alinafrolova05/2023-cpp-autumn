#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "The file does not open :(\n");
        return 1;
    }

    Number phone[50] = { 0 };
    int size = 0;
    writeInBuffer(file, phone, &size);
    fclose(file);

    printf("Before sorting:\n");
    print(phone, size);

    int choise = 5;
    while (choise != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Sort by name\n2.Sort by phone number");
        printf("\nNumber of option: ");
        Scanf(&choise);
        if (choise == 0) {
            break;
        }
        else if (choise == 1 || choise == 2) {
            mergeSort(phone, size, choise);
            printf("\nAfter sorting:\n");
            print(phone, size);
        }
        else {
            printf("\nInput wrong!");
        }
    }

    for (int i = 0; i < size; i++) {
        free(phone[i].name);
        free(phone[i].number);
    }
    return 0;
}
