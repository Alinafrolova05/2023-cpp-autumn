#include <stdio.h>
#include <stdbool.h>
#include "solution.h"

bool scanfChecker(int* add) {
    int result = scanf("%d", add);
    if (result != 1) {
        printf("\nInput wrong!");
        return false;
    }
    return true;
}

void printList(Element* element) {
    Element* current = element;
    while (element != NULL) {
        printf(" %d", getElementValue(element));
        element = elementNext(element);
    }
    element = current;
}

void solution(void) {
    Element* element = NULL;
    bool errorCode = true;
    int add = 0;
    int number = 5;

    while (number != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value to sorted list\n2.Remove value from list\n3.Print list");
        printf("\nNumber of option: ");
        if (!scanfChecker(&number)) {
            break;
        }
        if (number == 0) {
            break;
        }
        else if (number == 1) {
            printf("\nSpecify the number that will go into the list: ");
            if (!scanfChecker(&add)) {
                break;
            }
            addElement(&element, add, &errorCode);
            if (errorCode == false) {
                printf("Error!");
                return;
            }
            printf(" %d", getElementValue(element));
        }
        else if (number == 2) {
            printf("\nIndicate the value you want to delete: ");
            if (!scanfChecker(&add)) {
                break;
            }
            if (getElementValue(element) == add) {
                pop(&element);
            }
            else {
                deleteElement(&element, add);
            }
        }
        else if (number == 3) {
            printf("The array looks like this:");
            printList(element);
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }
    freeList(&element);
}
