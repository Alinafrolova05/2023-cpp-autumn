#ifndef MERGE_SORT
typedef struct Number {
    char* name;
    char* number;
} Number;

void Scanf(int* choise);
//checks if choice is an integer

void writeInBuffer(FILE* file, Number* phone, int* n);
//reads data from a file into arrays

void print(Number* phone, int size);
//prints numbers and phone numbers

void merge(Number* phone, Number* left, Number* right, int size, int choise);
//merges two arrays into one

void mergeSort(Number* phone, int size, int choise);
//splits into two arrays
#endif