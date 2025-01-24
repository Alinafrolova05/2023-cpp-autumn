#include <stdio.h>
#include "list.h"

void printList(Element* element1) {
    Element* pointer1 = element1;
    while (element1 != NULL) {
        printf(" %d", element1->value);
        element1 = element1->next;
    }
    element1 = pointer1;
}

void menu(Element** element) {
    bool errorCode = true;
    int add = 0;
    int number = 5;

    while (number != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value to sorted list\n2.Remove value from list\n3.Print list");
        printf("\nNumber of option: ");
        scanfChecker(&number);
        if (number == 0) {
            break;
        }
        else if (number == 1) {
            printf("\nSpecify the number that will go into the list: ");
            scanfChecker("%d", &add);
            addElement(element, add, &errorCode);
            if (errorCode == false) {
                printf("Error!");
                return;
            }
            printf(" %d", (*element)->value);
        }
        else if (number == 2) {
            printf("\nIndicate the value you want to delete: ");
            scanfChecker(&add);
            if ((*element)->value == add) {
                pop(element);
            }
            else {
                deleteElement(*element, add);
            }
        }
        else if (number == 3) {
            printf("The array looks like this:");
            printList(*element);
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }
}
