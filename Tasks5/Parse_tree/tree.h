#ifndef TREE
typedef struct Element {
    char value;
    struct Element* next1;
    struct Element* next2;
    struct Element* next;
}Element;

void push(Element** head, char value1);
void pop(Element** head);

void print(Element* numbers);
#endif