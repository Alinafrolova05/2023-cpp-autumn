#pragma once

#include "mergeSorting.h"
#include <stdio.h>

// Fills the list with numbers from the file.
void writeInBuffer(FILE* file, List** phoneList);

// Prints a list.
void printList(List* node);
