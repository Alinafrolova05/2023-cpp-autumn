#define _CRT_SECURE_NO_WARNINGS

#include "test.h"
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* myStrdup(const char* str, bool* errorCode) {
    if (str == NULL) {
        *errorCode = false;
        return NULL;
    }
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

bool test(void) {
    bool errorCode = true;
    Node* root = createNode();

    int array[] = { 8, 3, 9, 14, 13, 3, 1, 6 };
    char** value = (char**)malloc(8 * sizeof(char*));
    if (value == NULL) {
        return false;
    }

    for (int i = 0; i < 8; i++) {
        value[i] = myStrdup("val1", &errorCode);
        if (!errorCode) {
            for (int j = 0; j < i; j++) {
                free(value[j]);
            }
            free(value);
            return false;
        }
    }

    for (int i = 0; i < 8; ++i) {
        addElement(&root, array[i], value[i], &errorCode);
        if (!errorCode) {
            for (int j = 0; j < 8; j++) {
                free(value[j]);
            }
            free(value);
            return errorCode;
        }
    }

    deleteElement(&root, 13, &errorCode);
    if (!errorCode) {
        for (int j = 0; j < 8; j++) {
            free(value[j]);
        }
        free(value);
        return errorCode;
    }

    if (!(!search(root, 13) && search(root, 14))) {
        for (int j = 0; j < 8; j++) {
            free(value[j]);
        }
        free(value);
        return false;
    }

    freeTree(root);
    free(value);
    return errorCode;
}
