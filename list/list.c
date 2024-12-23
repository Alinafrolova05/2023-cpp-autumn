#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "oddNumberList.h"

int main(void)
{
    if (!test()) {
        printf("Error!");
        return -1;
    }

    Element* list = NULL;
    
    program(&list);

    while (list != NULL) {
        pop(&list);
    }
	return 0;
}
