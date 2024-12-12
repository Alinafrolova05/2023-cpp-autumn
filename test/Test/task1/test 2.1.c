#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main(void) {
    Node* root = NULL;

    int size = 5;
    int array[256] = { 0 };
    printf("Enter array: ");
    for (int i = 0; i < size; ++i) {
        int result = scanf("%d", &array[i]);
        add(&root, array[i]);
    }
    printf("\nSorted array: ");

    print(root);

    freeTree(root);
    return 0;
}
