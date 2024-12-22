#ifndef MARSHALLING_YARD

#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element* next;
}Element;

void push(Element** head, char value);
//adds an element to the stack

void pop(Element** head);
//removes an element from the stack

void print(Element* numbers);
//prints the result

void processInput(char* str, Element** numbers, Element** operations);
//converts an expression from infix form to postfix form

bool test(void);

#endif