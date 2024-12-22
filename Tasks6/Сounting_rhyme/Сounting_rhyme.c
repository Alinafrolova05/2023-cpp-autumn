#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

void count(Element** element1, int value) {
    if (value <= 2) {
        return;
    }
    (*element1)->value = value;
    for (int i = value - 1; i > 0; --i) {
        push(element1, i);
    }

    int i = 1;
    while ((*element1)->next->next->value != (*element1)->value) {
        i++;
        if (i % 3 == 0) {
            printf("%d %d ", i, (*element1)->value);
            deleteElement(*element1);
        }
        *element1 = (*element1)->next;
    }
}

bool test(void) {
    Element* element1 = calloc(1, sizeof(Element));
    Element* firstElement = element1;

    count(&element1, &firstElement, 42);

    free(element1->next);
    free(element1);
}

void print(Element* element1) {
    printf("First warrior's position: %d", element1->value);
    printf("\nSecond warrior's position: %d", element1->next->value);
}

int main(void) {
    Element* element1 = calloc(1, sizeof(Element));
    Element* firstElement = calloc(1, sizeof(Element));
    element1->next = firstElement;
    firstElement->next = element1;
    
    count(&element1, &firstElement, 4);
    
    print(element1);
    
    free(element1->next);
    free(element1);
    return 0;
}
