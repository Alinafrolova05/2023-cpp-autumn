#pragma once

#include "tree.h"

//
typedef struct Stack Stack;

//
void push(Stack** head, Tree* element, bool* errorCode);

//
Tree* pop(Stack** head);
