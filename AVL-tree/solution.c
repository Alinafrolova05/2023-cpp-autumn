#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void printFoundOrNot(Dictionary** dictionary, char keyToAdd[]) {
    if (search(dictionary, keyToAdd) == NULL) {
        printf("\nThere is no such key in the dictionary.\n");
    }
    else {
        printf("\nThere is such a key in the dictionary.\n");
    }
}

void writeLine(char line[], bool* error) {
    if (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[strcspn(line, "\n")] == '\0') {
            while (getchar() != '\n');
            *error = false;
            return;
        }
        line[strcspn(line, "\n")] = 0;
    }
}

void solution(void) {
    Dictionary* dictionary = NULL;
    bool errorCode = true;
    int answer = -1;

    while (answer != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value by key\n2.Get value by key\n3.Check for key availability\n4.Delete key.");
        printf("\nNumber of option: ");
        scanf("%d", &answer);
        getchar(); 
        if (answer == 0) {
            break;
        }
        else if (answer == 1) {
            char keyToAdd[256] = "";
            printf("\nWrite the key: ");
            bool error = true;
            writeLine(keyToAdd, &error);
            if (!error) {
                printf("Input was too long for the key, please try again.\n");
                continue;
            }

            char valueToAdd[256] = "";
            printf("\nWrite the key value: ");
            writeLine(keyToAdd, &error);
            if (!error) {
                printf("Input was too long for the key, please try again.\n");
                continue;
            }
            
            insert(&dictionary, keyToAdd, valueToAdd, NULL);
        }
        else if (answer == 2) {
            char keyToAdd[256] = "";
            printf("\nSpecify the key: ");
            bool error = true;
            writeLine(keyToAdd, &error);
            if (!error) {
                printf("Input was too long for the key, please try again.\n");
                continue;
            }

            Dictionary* found = search(&dictionary, keyToAdd);
            if (found == NULL) {
                printf("\nThere is no such key in the dictionary.\n");
            } else {
                printf("\nValue: %s\n", getValue(found));
            }
        } else if (answer == 3) {
            char keyToAdd[256] = "";
            printf("\nSpecify the key: ");
            bool error = true;
            writeLine(keyToAdd, &error);
            if (!error) {
                printf("Input was too long for the key, please try again.\n");
                continue;
            }

            printFoundOrNot(&dictionary, keyToAdd);
        } else if (answer == 4) {
            char keyToAdd[256] = "";
            printf("\nSpecify the key: ");
            bool error = true;
            writeLine(keyToAdd, &error);
            if (!error) {
                printf("Input was too long for the key, please try again.\n");
                continue;
            }

            printFoundOrNot(&dictionary, keyToAdd);
        } else {
            printf("\nInput wrong!");
            break;
        }
    }
    freeTree(&dictionary);
}
