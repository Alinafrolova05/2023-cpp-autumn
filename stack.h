#pragma once

#include <stdbool.h>
#include "balance.h"

// Adds an element to the top of the stack.
void push(Element** head, char value, bool* errorCode);

// Removes the top element from the stack.
void pop(Element** head);
