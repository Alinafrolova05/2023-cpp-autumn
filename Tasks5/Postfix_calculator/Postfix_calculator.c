﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    int answer = 0;
    Element* element1 = calloc(1, sizeof(Element));
    if (!test(element1, &answer)) {
        printf("Error!!!");
        return -1;
    }
    return 0;
}
