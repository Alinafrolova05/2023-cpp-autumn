#pragma once

#include "solution.h"

// Sets a new value to the next element in a circular list.
void push(Element** front, int value);

// Removes the value of the next element in a circular list.
void deleteElement(Element** front);
