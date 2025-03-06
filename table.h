#pragma once

#include <stdbool.h>

// Defines the structure.
typedef struct HashTable HashTable;

// Fills table.
//HashTable* fillOutTheTable(const char* array[], int arraySize, bool* errorCode, int** task);

// Process the input array and calculate statistics.
void solution(const char* array[], int arraySize, bool* errorCode, int** task);

// Print the results of the solution, including the hash table and statistics.
int printTable(const char* array[], int arraySize, bool* errorCode, int** task);
