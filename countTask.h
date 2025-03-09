#pragma once

// Defines the structure.
typedef struct CountTask CountTask;

// Creates and initializes the structure.
CountTask* createCountTask(void);

// Retrieves the size of the array value from the structure.
int getArraySize(CountTask* task);

// Retrieves the average length of the list value from the structure.
int getAverageListLength(CountTask* task);

// Retrieves the max length of the list value from the structure.
int getMaxListLength(CountTask* task);

// Sets the size of the array in the structure.
void setArraySize(CountTask* task, int value);

// Sets the average length of the lists in the structure.
void setAverageListLength(CountTask* task, int value);

// Sets the maximum length of the lists in the structure.
int setMaxListLength(CountTask* task, int value);
