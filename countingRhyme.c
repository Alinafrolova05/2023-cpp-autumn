#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "solution.h"
#include "test.h"

int main(void) {
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    printf("Answer: %d", count(41, 3));

    return 0;
}
