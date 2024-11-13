#ifndef MARSHALLING_YARD
#include <stdbool.h>
typedef struct Element {
    int value;
    struct Element* next;
}Element;
void push(Element** head, int value);
void pop(Element** head);
void print(Element* numbers, Element* pointerOut);
#endif