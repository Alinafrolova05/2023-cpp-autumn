#ifndef COUNTING_RHYME

typedef struct Element {
    int value;
    struct Element* next;
}Element;

void push(Element** front, int value);

void deleteElement(Element* front);

#endif