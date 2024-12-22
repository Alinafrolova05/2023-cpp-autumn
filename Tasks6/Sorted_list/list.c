#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include "list.h"

void Scanf(int* add) {
    int result = scanf("%d", add);
    if (result != 1) {
        printf("\nInput wrong!");
        return -1;
    }
}

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void addElement(Element** head, int value1) {
    Element* element1 = calloc(1, sizeof(Element));
    element1->value = value1;
    if ((*head) == NULL || (*head)->value <= value1) {
        element1->next = *head;
        *head = element1;
        return;
    }

    Element* pointer1 = *head;
    while ((*head)->next != NULL && (*head)->next->value >= value1) {
        *head = (*head)->next;
    }

    element1->next = (*head)->next;
    (*head)->next = element1;
    *head = pointer1;
}

void deleteElement(Element* head, int value1) {
    if (head == NULL || head->value < value1) {
        return;
    }
    Element* pointer1 = head;
    while (head->next->value != value1) {
        if (head->next == NULL || head->next->value < value1) {
            head = pointer1;
            return;
        }
        head = head->next;
    }
    Element* deleting = head->next;
    head->next = head->next->next;
    free(deleting);
    head = pointer1;
}

void printList(Element* element1) {
    Element* pointer1 = element1;
    while (element1 != NULL) {
        printf(" %d", element1->value);
        element1 = element1->next;
    }
    element1 = pointer1;
}

void menu(Element** element) {
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
            Scanf("%d", &add);
            addElement(element, add);
            printf(" %d", (*element)->value);
        }
        else if (number == 2) {
            printf("\nIndicate the value you want to delete: ");
            Scanf(&add);
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

bool test(void) {
    Element* element = NULL;

    addElement(&element, 5);
    addElement(&element, 6);

    int array[] = { 5, 6 };
    int checkArray[2] = { 0 };
    int i = 0;

    while (element != NULL) {
        checkArray[i++] = element->value;
        element = element->next;
    }

    if (sizeof(array) / sizeof(array[0]) != i) {
        return false;
    }

    for (int j = 0; j < i; ++j) {
        if (array[j] != checkArray[i - j - 1]) {
            return false;
        }
    }

    deleteElement(element, 5);
    deleteElement(element, 6);

    return element == NULL;
}
