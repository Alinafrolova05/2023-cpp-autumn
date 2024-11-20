#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

int main(void) {
    Element* element1 = calloc(1, sizeof(Element));
    element1->key = NULL;
    element1->value = NULL;
    Element* pointer = element1;

    int addingKey = 5;
    char* addingValue = calloc(20, sizeof(char));
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
            printf("\nWrite the key value with less than 20 characters: ");
            fgets(&addingValue, 20, stdin);
            add(&element1, addingKey, addingValue);
        }
        else if (answer == 2 || answer == 3) {
            printf("\nSpecify the key: ");
            Scanf(&addingKey);
            if (search(element1, addingKey) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                printf("\nValue: %s", addingValue[0]);
            }
        }   
        else if (answer == 4) {
            printf("\nSpecify the key: ");
            Scanf(&addingKey);
            if (search(element1, addingKey) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                deleteElement(element1, addingKey);
                printf("\nThe value and key have been deleted.");
            }
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }
    return 0;
}
