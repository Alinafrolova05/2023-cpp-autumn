#ifndef LIST
#define LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element* next;
}Element;

void push(Element** head, int value);
//puts on the stack

void pop(Element** head);
//removes the top of the stack

void program(Element** list);
//input and output

bool test(void);

#endif
