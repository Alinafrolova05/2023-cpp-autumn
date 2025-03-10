#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "test.h"

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    return 0;
}
