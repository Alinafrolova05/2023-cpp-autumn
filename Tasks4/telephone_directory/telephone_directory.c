#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>
#include "directory.h"

int main(void) {
    FILE* file = fopen("text.txt", "a+");
    if (file == NULL) {
        printf("\nFile doesn't open!");
        return -1;
    }
    if (!test(file)) {
        printf("Error!");
        return -1;
    }

    int size = 0;
    setlocale(LC_ALL, "Rus");
    PhoneBook* entry = malloc(sizeof(PhoneBook) * 10);
    printf("Specify option number:\n");
    printf("0 - exit \n1 - add an entry(name and phone number) \n2 - print all existing records \n3 - find a phone by name \n4 - find a name by phone \n5 - save current data to file");

    choices(file, entry, size);

    free(entry);
    fclose(file);
    return 0;
}