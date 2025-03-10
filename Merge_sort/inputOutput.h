#pragma once

#include "sort.h"
#include <stdio.h>
#include "mergeSorting.h"

// 
typedef struct Number Number;

// 
Number* createNumber();

// 
char* getName(Number* number);

// 
char* getNumber(Number* number);

// 
void toCheckScanf(SortChoice* choice);

// 
void writeInBuffer(FILE* file, List** phoneList);

// 
void printList(List* node);
