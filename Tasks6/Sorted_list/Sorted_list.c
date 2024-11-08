#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    Element* element = calloc(1, sizeof(Element));
    Element* element2 = calloc(1, sizeof(Element));
    element->value = 1;
    element->next = element2;
    element = element2;

    Element* first = element;
    int testFirst = 0;

    int add = 6;
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
            Element* rememberStart = element;
            addElement(&element, add);
            element = rememberStart;
            free(rememberStart);
        }
        else if (number == 2) {
            printf("\nIndicate the value you want to delete: ");
            Scanf(&add);
            Element* rememberStart = element;
            deleteElement(&element, add);
            element = rememberStart;
            free(rememberStart);
        }
        else if (number == 3) {
            printf("The array looks like this:");
            Element* rememberStart = element;
            printList(element);
            element = rememberStart;
            free(rememberStart);
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }

    while (element != first) {
        pop(element);
    }
    pop(element);
    return 0;
}
