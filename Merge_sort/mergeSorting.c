#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void merge(Number* phone, Number* left, Number* right, int size, SortChoice choice) {
    int index1 = 0;
    int index2 = 0;
    int i = 0;

    while (index1 < size / 2 && index2 < size - size / 2) {
        if ((choice == SORT_BY_NAME && strcmp(left[index1].name, right[index2].name) <= 0) ||
            (choice == SORT_BY_NUMBER && strcmp(left[index1].number, right[index2].number) <= 0)) {
            phone[i] = left[index1];
            index1++;
        } else {
            phone[i] = right[index2];
            index2++;
        }
        i++;
    }
    while (index1 < size / 2) {
        phone[i] = left[index1];
        i++;
        index1++;
    }
    while (index2 < size - size / 2) {
        phone[i] = right[index2];
        i++;
        index2++;
    }
}

void mergeSort(Number* phone, int size, SortChoice choice) {
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
    mergeSort(left, size / 2, choice);
    mergeSort(right, size - size / 2, choice);

    merge(phone, left, right, size, choice);

    free(left);
    free(right);
}
