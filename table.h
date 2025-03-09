#pragma once

#include <stdbool.h>
#include "countTask.h"

// Defines the structure.
typedef struct HashTable HashTable;

// Process the input array and calculate statistics.
void solution(const char* array[], int arraySize, bool* errorCode, CountTask** task);

// Print the results of the solution, including the hash table and statistics.
int printTable(const char* array[], int arraySize, bool* errorCode, CountTask** task);
