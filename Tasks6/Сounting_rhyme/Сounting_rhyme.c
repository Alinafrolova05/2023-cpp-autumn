#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    Element* element1 = malloc(sizeof(Element));
    element1->value = 42;
    Element* firstElement = element1;
    for (int i = 41; i > 0; --i) {
        push(&element1, i, &firstElement);
    }

    int i = 1;
    while (element1->next->next->value != element1->value) {
        element1 = element1->next;
        if (i % 3 == 0) {
            deleteElement(element1);
        }
        i++;
    }
    printf("First warrior's position: %d", element1->value);
    printf("\nSecond warrior's position: %d", element1->next->value);
    free(element1->next);
    free(element1);
    return 0;
}
