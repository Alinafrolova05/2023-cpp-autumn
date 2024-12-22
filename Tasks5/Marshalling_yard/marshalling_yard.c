#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {

    char str[100] = "";
    printf("Enter numbers and operations: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    Element* numbers = NULL;
    Element* operations = NULL;
   
    processInput(str, &numbers, &operations);

    while (operations != NULL) {
        push(&numbers, operations->value);
        pop(&operations);
    }

    print(numbers);
    return 0;
}
