#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>
#include "directory.h"
#include "test.h"

void printSolution(FILE* file, PhoneBook* entry, int size) {
    int answer = 8;
    printf("\nAnswer: ");
    int result = scanf("%d", &answer);

    while (answer != 0) {
        if (answer == 1) {
            printf("name = ");
            int res = scanf("%s", getName(entry, size));
            printf("number = ");
            res = scanf("%s", getNumber(entry, size));
            size++;
        }
        else if (answer == 2) {
            printAllFile(file);
        }
        else if (answer == 3) {
            bool errorCode = true;
            char name[20] = { 0 };
            printf("\nInput name: ");
            int res = scanf("%s", name);
            char buffer[50] = { 0 };
            find(file, name, buffer, &errorCode);
            if (!errorCode) {
                printf("\nThis name was not found.");
                continue;
            }
            printf("%s", buffer);
        }
        else if (answer == 4) {
            bool errorCode = true;
            char number[20] = { 0 };
            printf("\nInput number: ");
            int res = scanf("%s", number);
            char buffer[50] = { 0 };
            find(file, number, buffer, &errorCode);
            if (!errorCode) {
                printf("\nThis name was not found.");
                continue;
            }
            printf("%s", buffer);
        }
        else if (answer == 5) {
            printInFile(file, entry, size);
            break;
        }
        else {
            printf("\nInput Error!!!!!");
            break;
        }
        printf("\nNext answer: ");
        result = scanf("%d", &answer);
    }
}

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

    printf("Specify option number:\n");
    printf("0 - exit");
    printf("\n1 - add an entry(name and phone number)");
    printf("\n2 - print all existing records");
    printf("\n3 - find a phone by name");
    printf("\n4 - find a name by phone");
    printf("\n5 - save current data to file");

    int size = 0;
    PhoneBook* entry = createPhoneBook();
    printSolution(file, entry, size);

    free(entry);
    fclose(file);
    return 0;
}
