#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

int main() {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    return 0;
}