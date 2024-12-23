#ifndef LIST
#define LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element Element;

void push(Element** head, int value, bool* errorCode);
//puts on the stack

void pop(Element** head);
//removes the top of the stack

void solution(Element** list, bool* errorCode);
//input and output

bool test(void);

Element* createList(void);

#endif
