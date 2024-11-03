#ifndef POSTFIX_CALCULATOR
#include <stdbool.h>
bool testZero(int number);
//check the divisor if the division operation is used
typedef struct Element {
    int value;
    struct Element* next;
}Element;
void push(Element** head, int value);
//adding an element to the stack
void pop(Element** head2);
//remove an element from the stack
void operation(Element* element1, char str[], int i, int* answer);
//a function that performs one of the arithmetic operations
void numbers(Element* element1, char str[], int* answer);
//a function either refers to a "push" function or refers to an "operation" function
bool test(Element* element1, int answer);
#endif