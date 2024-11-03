#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "functions.h"

int main()
{
    int answer = 0;
    Element* element1 = calloc(1, sizeof(Element));
    if (!test(element1, &answer)) {
        printf("\nError!!!");
        return -1;
    }
    char str[100] = { 0 };
    printf("Enter numbers and operations: ");
    gets(str, 100, stdin);
    numbers(element1, str, &answer);
    printf("\nAnswer = %d", answer);
    free(element1);
    return 0;
}
