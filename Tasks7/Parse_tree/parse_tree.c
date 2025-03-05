#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    char expression[] = " (+3(*45))"; // Пример выражения
    printf("Expression: %s\n", expression);
    printf("Result: %d\n", resultOfCounting(expression));
    printf("Tree: ");
    printTree(expression);
    printf("\n");
    return 0;
}

