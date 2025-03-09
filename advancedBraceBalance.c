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
    char* answerString = solution(str, &errorCode);
    if (!errorCode) {
        printf("Error!!!");
        return;
    }
    printf("Unbalanced parentheses: %s", answerString);
    free(answerString);
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
