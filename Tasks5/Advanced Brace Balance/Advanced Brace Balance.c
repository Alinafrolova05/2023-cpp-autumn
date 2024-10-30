#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "module.h"

int main(void) {
    printf("Enter less than 100 characters: ");
    char str[100] = "0";
    fgets(str, 99, stdin);
    
    Element* element1 = malloc(sizeof(Element));
    element1->next = NULL;
    Element* pointer = element1;
    
    fillStack(element1, str);

    while (element1 != pointer) {
        printf(" %c is wrong ",element1->brace);
        free(element1);
    }
    free(element1);
}
