#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    if (test() != 0) {
        printf("Error!");
        return -1;
    }
    return 0;
}