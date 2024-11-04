#ifndef MARSHALLING_YARD
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

#endif