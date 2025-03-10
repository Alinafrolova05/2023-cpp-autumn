#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "balance.h"
#include "stack.h"
#include "test.h"

void printSolution(void) {
    bool errorCode = true;
    char str[256] = "";
    printf("Enter string: ");
    fgets(str, 256, stdin);
    bool result = processBraces(str);

    if (result) {
        printf("Braces are balanced.\n");
    }
    else {
        printf("Braces are not balanced.\n");
    }
}

int main(void)
{
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    printSolution();
    return 0;
}
