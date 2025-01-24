#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "list.h"

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }

    Element* element = NULL;

    menu(&element);

    freeList(&element);

    return 0;
}
