#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>
#include "module.h"


int main() {
    FILE* file = fopen("text.txt", "a+");
    if (file == NULL) {
        printf("\nFile doesn't open!");
        return -1;
    }
    int size = 0;
    setlocale(LC_ALL, "Rus");
    PhoneBook *entry = malloc(sizeof(PhoneBook) * 10);
    printf("Specify option number:\n");
    printf("0 - exit \n1 - add an entry(name and phone number) \n2 - print all existing records \n3 - find a phone by name \n4 - find a name by phone \n5 - save current data to file");
    int answer = 8;
    printf("\nAnswer: ");
    int result = scanf("%d", &answer);
   
    while (answer != 0) {
        if (answer == 1) {
            printf("name = ");
            scanf("%s", entry[size].name);
            printf("number = ");
            scanf("%s", entry[size].number);
            size++;
        }
        else if (answer == 2) {
            printAllFile(file);
        }
        else if (answer == 3) {
            char name[20] = { 0 };
            printf("\nInput name: ");
            int res = scanf("%s", name);
            find(file, name);
        }
        else if (answer == 4) {
            char number[20] = { 0 };
            printf("\nInput number: ");
            int res = scanf("%s", number);
            find(file, number);
        }
        else if (answer == 5) {
            printFile(file, entry, size);
            return 0;
        }
        else {
            printf("\nInput Error!!!!!");
            free(entry);
            return -1;
        }
        printf("\nNext answer: ");
        result = scanf("%d", &answer);
    }
    
    free(entry);
    fclose(file);
    return 0;
}
