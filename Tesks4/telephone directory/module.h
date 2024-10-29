#ifndef H
#include <stdbool.h>
FILE* file;
typedef struct PhoneBook {
    char name[12];
    char number[14];
}PhoneBook;
bool testScanf(int result);
void write(PhoneBook* entry, int size);
void printAllFile(FILE* file);
void printFile(FILE* file, PhoneBook* entry, int size);
void find(FILE* file, char* name);
#endif