#pragma once

#include "sort.h"
#include "inputOutput.h"

// 
typedef struct List List;

// 
void freeList(List** phoneList);

// 
List* getNextList(List* list);

// 
Number* getNumberOfList(List* list);

// 
List* createNode(Number* element);

// 
List* merge(List* left, List* right, SortChoice choice);

// 
void split(List* source, List** left, List** right);

// 
void mergeSort(List** element, SortChoice choice);
