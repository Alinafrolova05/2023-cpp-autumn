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
//
void Scanf(int* add);
//
void addElement(Element** front, int value);
//
void deleteElement(Element** front, int value);
//
void printList(Element* element1);
//
void pop(Element* head);
#endif