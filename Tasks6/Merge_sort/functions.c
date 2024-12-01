#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

void Scanf(int* choise) {
    while (true) {
        int result = scanf("%d", choise);
        if (result != 1) {
            printf("\nInput wrong! Please enter a number: ");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    }
}

void writeInBuffer(FILE* file, Number* phone, int* n) {
    int k = 0;
    while (!feof(file)) {
        char* array = calloc(256, sizeof(char));
        if (fgets(array, 256, file) != NULL) {
            char* arrayForName = calloc(256, sizeof(char));
            char* arrayForNumber = calloc(256, sizeof(char));
            int i = 0;
            while (array[i] != '-' && array[i] != '\0') {
                arrayForName[i] = array[i];
                i++;
            }
            arrayForName[i] = '\0';
            i++;
            int j = 0;
            while (array[i] != '\0') {
                arrayForNumber[j] = array[i];
                i++;
                j++;
            }
            arrayForNumber[j] = '\0';
            phone[k].name = arrayForName;
            phone[k].number = arrayForNumber;
            k++;
        }
        free(array);
    }
    *n = k;
}

void print(Number* phone, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s%s", phone[i].name, phone[i].number);
    }
}

void merge(Number* phone, Number* left, Number* right, int size, int choise) {
    int pointer1 = 0;
    int pointer2 = 0;
    int i = 0;

    while (pointer1 < size / 2 && pointer2 < size - size / 2) {
        if ((choise == 1 && strcmp(left[pointer1].name, right[pointer2].name) <= 0) ||
            (choise != 1 && strcmp(left[pointer1].number, right[pointer2].number) <= 0)) {
            phone[i] = left[pointer1];
            pointer1++;
        }
        else {
            phone[i] = right[pointer2];
            pointer2++;
        }
        i++;
    }
    while (pointer1 < size / 2) {
        phone[i] = left[pointer1];
        i++;
        pointer1++;
    }
    while (pointer2 < size - size / 2) {
        phone[i] = right[pointer2];
        i++;
        pointer2++;
    }
}

void mergeSort(Number* phone, int size, int choise) {
    if (size <= 1) {
        return;
    }
    Number* left = (Number*)calloc(size / 2, sizeof(Number));
    Number* right = (Number*)calloc(size - size / 2, sizeof(Number));

    for (int i = 0; i < size / 2; ++i) {
        left[i] = phone[i];
    }
    for (int i = size / 2; i < size; ++i) {
        right[i - size / 2] = phone[i];
    }
    mergeSort(left, size / 2, choise);
    mergeSort(right, size - size / 2, choise);

    merge(phone, left, right, size, choise);

    free(left);
    free(right);
}
