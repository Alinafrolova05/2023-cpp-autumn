#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

int main(void) {
    Node* root = NULL;
    
    char array[20] = { 0 };
    int addingKey = 0;
    int answer = -1;

    while (answer != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value by key\n2.Get value by key\n3.Check for key availability\n4.Delete key.");
        printf("\nNumber of option: ");
        Scanf(&answer);
        if (answer == 0) {
            break;
        }
        else if (answer == 1) {
            printf("\nWrite the key: ");
            Scanf(&addingKey);
            char* addingValue = calloc(256, sizeof(char));
            printf("\nWrite the key value with less than 20 characters: ");
            getchar();
            fgets(addingValue, 256, stdin);
            add(&root, addingKey, addingValue);
        }
        else if (answer == 2 || answer == 3) {
            printf("\nSpecify the key: ");
            Scanf(&addingKey);
            Node* founded = search(root, addingKey);
            if (founded == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                printf("\nValue: %s", founded->element->value);
            }
        }   
        else if (answer == 4) {
            printf("\nSpecify the key: ");
            Scanf(&addingKey);
            if (search(root, addingKey) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                deleteElement(&root, addingKey);
                printf("\nThe value and key have been deleted.");
            }
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }
    freeTree(root);
    return 0;
}
