#ifndef COUNTING_RHYME
typedef struct Element {
    int value;
    struct Element* next;
}Element;
void push(Element** head, int value, Element** firstElement);
void deleteElement(Element* front);
#endif