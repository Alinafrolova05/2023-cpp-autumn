#pragma once

typedef struct Element Element;

typedef struct Stack Stack;

// Puts on the stack.
void push(Stack** head, Element* element);

// Removes the top of the stack.
Element* pop(Stack** head);

// Prints tree.
void print(Element* element);

void printTree(char* str);

// Builds a tree.
Stack* tree(char* str);

//
int resultOfCounting(char* str);