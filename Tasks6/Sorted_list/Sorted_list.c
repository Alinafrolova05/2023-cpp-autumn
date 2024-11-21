#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    Element* element = calloc(1, sizeof(Element));
    Element* pointer = element;

    int add = 0;
    int number = 5;

    while (number != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value to sorted list\n2.Remove value from list\n3.Print list");
        printf("\nNumber of option: ");
        Scanf(&number);
        if (number == 0) {
            break;
        }
        else if (number == 1) {
            printf("\nSpecify the number that will go into the list: ");
            Scanf(&add);
            addElement(&element, pointer, add);
            printf(" %d", element->value);
        }
        else if (number == 2) {
            printf("\nIndicate the value you want to delete: ");
            Scanf(&add);
            if (element->value == add) {
                pop(&element);
            }
            else {
                deleteElement(element, pointer, add);
            }
        }
        else if (number == 3) {
            printf("The array looks like this:");
            printList(element, pointer);
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }

    while (element != pointer) {
        pop(&element);
    }
    pop(&element);
    return 0;
}
