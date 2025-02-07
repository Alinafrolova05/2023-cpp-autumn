#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "balance.h"
#include "stack.h"
#include "test.h"

void solution(void) {
    bool errorCode = true;
    char str[256] = "";
    char check[256] = "";
    printf("Enter string: ");
    fgets(str, 256, stdin);
    processBraces(str, &errorCode, check);
    printf("Incorrect parentheses: ");
    puts(check);
}

int main(void)
{
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    solution();
    return 0;
}
