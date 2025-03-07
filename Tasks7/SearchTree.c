#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include "test.h"

void solution(Dictionary** dictionary) {
    bool errorCode = true;

    int answer = -1;
    int keyToAdd = 0;

    while (answer != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value by key\n2.Get value by key\n3.Check for key availability\n4.Delete key.");
        printf("\nNumber of option: ");
        checkScanf(&answer, &errorCode);
        if (answer == 0) {
            break;
        }
        else if (answer == 1) {
            printf("\nWrite the key: ");
            checkScanf("%d", &keyToAdd);
            char valueToAdd[256] = "";
            if (!errorCode) {
                printf("Error!");
                return;
            }
            printf("\nWrite the key value with less than 20 characters: ");
            getchar();
            fgets(valueToAdd, 256, stdin);
            addElement(dictionary, keyToAdd, valueToAdd, &errorCode);
            if (!errorCode) {
                free(valueToAdd);
                printf("Error!");
                return;
            }
            free(valueToAdd);
        }
        else if (answer == 2) {
            printf("\nSpecify the key: ");
            checkScanf(&keyToAdd, &errorCode);
            if (search(*dictionary, keyToAdd) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                printf("\nValue: %s", getValue(search(*dictionary, keyToAdd)));
            }
        } else if (answer == 3) {
            printf("\nSpecify the key: ");
            checkScanf(&keyToAdd, &errorCode);
            if (search(*dictionary, keyToAdd) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            } else {
                printf("\nThere is such key in the dictionary.");
            }
        }
        else if (answer == 4) {
            printf("\nSpecify the key: ");
            checkScanf(&keyToAdd, &errorCode);
            if (search(*dictionary, keyToAdd) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                deleteElement(dictionary, keyToAdd, &errorCode);
                printf("\nThe value and key have been deleted.");
            }
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }
}

int main(void) {
    if (!test()) {
        printf("Error!");
        return;
    }
    Dictionary* dictionary = createNode();
    solution(&dictionary);
    freeTree(dictionary);
    return 0;
}
