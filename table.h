#pragma once

#include <stdbool.h>

// Function prototype to get the size of the hash table.
int getSizeOfTable(void);

// Function prototype to process the input array and calculate statistics.
void solution(char* array[], int arraySize, bool* errorCode, float** task);

// Function prototype to print the results of the solution, including the hash table and statistics.
void printSolution(char* array[], int arraySize, bool* errorCode, float** task);
