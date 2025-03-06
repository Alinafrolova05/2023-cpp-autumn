#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "solution.h"

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    solution();
    return 0;
}
