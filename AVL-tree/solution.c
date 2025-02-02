#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "tree.h"

struct Node {
    const char* key;
    const char* value;
    int balance;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

void solution(void) {
    Node* root = NULL;
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
            if (fgets(keyToAdd, sizeof(keyToAdd), stdin) != NULL) {
                if (keyToAdd[strcspn(keyToAdd, "\n")] == '\0') {
                    while (getchar() != '\n');
                    printf("Input was too long for the key, please try again.\n");
                    continue;
                }
                keyToAdd[strcspn(keyToAdd, "\n")] = 0;
            }

            char valueToAdd[256] = "";
            printf("\nWrite the key value: ");
            if (fgets(valueToAdd, sizeof(valueToAdd), stdin) != NULL) {
                if (valueToAdd[strcspn(valueToAdd, "\n")] == '\0') {
                    while (getchar() != '\n');
                    printf("Input was too long for the value, please try again.\n");
                    continue;
                }
                valueToAdd[strcspn(valueToAdd, "\n")] = 0;
            }

            insert(&root, keyToAdd, valueToAdd, NULL);
        }
        else if (answer == 2) {
            char keyToAdd[256] = "";
            printf("\nSpecify the key: ");
            if (fgets(keyToAdd, sizeof(keyToAdd), stdin) != NULL) {
                if (keyToAdd[strcspn(keyToAdd, "\n")] == '\0') {
                    while (getchar() != '\n');
                    printf("Input was too long for the key, please try again.\n");
                    continue;
                }
                keyToAdd[strcspn(keyToAdd, "\n")] = 0;
            }

            Node* found = search(&root, keyToAdd);
            if (found == NULL) {
                printf("\nThere is no such key in the dictionary.\n");
            } else {
                printf("\nValue: %s\n", found->value);
            }
        } else if (answer == 3) {
            char keyToAdd[256] = "";
            printf("\nSpecify the key: ");
            if (fgets(keyToAdd, sizeof(keyToAdd), stdin) != NULL) {
                if (keyToAdd[strcspn(keyToAdd, "\n")] == '\0') {
                    while (getchar() != '\n');
                    printf("Input was too long for the key, please try again.\n");
                    continue;
                }
                keyToAdd[strcspn(keyToAdd, "\n")] = 0;
            }

            Node* found = search(&root, keyToAdd);
            if (found == NULL) {
                printf("\nThere is no such key in the dictionary.\n");
            } else {
                printf("\nThere is such a key in the dictionary.\n");
            }
        } else if (answer == 4) {
            char keyToAdd[256] = "";
            printf("\nSpecify the key: ");
            if (fgets(keyToAdd, sizeof(keyToAdd), stdin) != NULL) {
                if (keyToAdd[strcspn(keyToAdd, "\n")] == '\0') {
                    while (getchar() != '\n');
                    printf("Input was too long for the key, please try again.\n");
                    continue;
                }
                keyToAdd[strcspn(keyToAdd, "\n")] = 0;
            }

            if (search(&root, keyToAdd) == NULL) {
                printf("\nThere is no such key in the dictionary.\n");
            } else {
                deleteElement(&root, keyToAdd, NULL);
                printf("\nThe value and key have been deleted.\n");
            }
        } else {
            printf("\nInput wrong!");
            break;
        }
    }
    freeTree(&root);
}
