#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "module.h"

int main()
{
    FILE* file1 = fopen("input.txt", "r");
    FILE* file2 = fopen("output.txt", "w");
    if (!testFile(file1)) {
        printf("Error!");
        return -1;
    }
    if (!testFile(file2)) {
        printf("Error!");
        fclose(file1);
        return -1;
    }
    char str[100] = { 0 };
    fillArray(file1, str);
    printInFile(file2, str);
    fclose(file1);
    fclose(file2);
    return 0;
}
