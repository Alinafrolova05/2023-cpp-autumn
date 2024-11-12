#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "module.h"

int main()
{
    printf("Enter less than 100 characters: ");
    char str[100] = "0";
    fgets(str, 99, stdin);

    Element* element1 = calloc(1, sizeof(Element));
    Element* pointerFirst = element1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
            push(&element1, str[i]);
            if (element1->brace == ')' && element1->next->brace == '(') {
                pop(&element1);
                pop(&element1);
            }
            else if (element1->brace == '}' && element1->next->brace == '{') {
                pop(&element1);
                pop(&element1);
            }
            else if (element1->brace == ']' && element1->next->brace == '[') {
                pop(&element1);
                pop(&element1);
            }
        }
    }

    printf("Incorrect parentheses: ");
    while (element1 != pointerFirst) {
        printf("%c, ", element1->brace);
        pop(&element1);
    }
    free(element1);
    return 0;
}
