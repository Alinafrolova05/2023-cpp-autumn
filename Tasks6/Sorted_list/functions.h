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
bool testScanf(int result);
//checks scanf

void Scanf(int* add);
//entering a number with verification

void addElement(Element** head, Element* pointer, int value);
//adds an element to the stack

void deleteElement(Element* head, Element* pointer, int value);
//deletes an element to the stack

void printList(Element* element1, Element* pointer);
//print stack

void pop(Element** head);
//removes the top element from the stack

#endif