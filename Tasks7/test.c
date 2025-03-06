#include "test.h"
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool test(void) {
    bool errorCode = true;
    Dictionary* dictionary = createNode();
    
    int array[] = { 8, 3, 9, 14, 13, 3, 1, 6 };
    char** value = (char**)malloc(8 * sizeof(char*));
    if (value == NULL) {
        freeTree(dictionary);
        return false;
    }

    for (int i = 0; i < 8; i++) {
        value[i] = myStrdup("val1", &errorCode);
        if (!errorCode) {
            for (int j = 0; j < i; j++) {
                free(value[j]);
            }
            free(value);
            freeTree(dictionary);
            return false;
        }
    }

    for (int i = 0; i < 8; ++i) {
        addElement(&dictionary, array[i], value[i], &errorCode);
        if (!errorCode) {
            for (int j = 0; j < 8; j++) {
                free(value[j]);
            }
            free(value);
            freeTree(dictionary);
            return errorCode;
        }
    }

    deleteElement(&dictionary, 13, &errorCode);
    if (!errorCode) {
        for (int j = 0; j < 8; j++) {
            free(value[j]);
        }
        free(value);
        freeTree(dictionary);
        return errorCode;
    }

    if (!(!search(dictionary, 13) && search(dictionary, 14))) {
        for (int j = 0; j < 8; j++) {
            free(value[j]);
        }
        free(value);
        freeTree(dictionary);
        return false;
    }

    freeTree(dictionary);
    free(value);
    return errorCode;
}
