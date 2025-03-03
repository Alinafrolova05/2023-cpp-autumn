#pragma once

#include "solution.h"

// Adds a new element with vertex and weight to the front of the list.
void push(Element** head, int vertex, int weight, bool* errorCode);

// Removes the element at the front of the list, if it exists.
void pop(Element** head);
