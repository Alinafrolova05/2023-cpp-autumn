#pragma once

#include <stdbool.h>

// Function to process braces in the input string and remove valid elements from the stack
void processBraces(char* str, bool* errorCode, char check[]);

// Solves the task.
char* solution(char str[], bool* errorCode);
