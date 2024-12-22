#ifndef TREE

typedef struct Element {
    char value;
    int result;
    struct Element* leftChild;
    struct Element* rightChild;
} Element;

typedef struct Stack {
    Element* element;
    struct Stack* next;
} Stack;

void push(Stack** head, Element* element);
//puts on the stack

Element* pop(Stack** head);
//removes the top of the stack

void print(Element* element);
//prints tree

void count(Element* element);
//calculates the value of an expression

int precedence(char value);
//produces different numbers depending on the operator

void tree(char* str, Stack** numberStack, Stack** operationStack);
//builds a tree

void printAlgorithm(void);

#endif