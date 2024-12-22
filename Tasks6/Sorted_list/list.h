#ifndef SORTED_LIST

#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element* next;

}Element;

struct List {
    struct Element* front;
    struct Element* back;
};

void Scanf(int* add);
//entering a number with verification

void addElement(Element** head, int value);
//adds an element to the stack

void deleteElement(Element* head, int value);
//deletes an element to the stack

void printList(Element* element1);
//print stack

void pop(Element** head);
//removes the top element from the stack

void menu(Element** element);

bool test();

#endif