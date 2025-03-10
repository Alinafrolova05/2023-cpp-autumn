#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "operations.h"
#include "stack.h"
#include "test.h"

int main(void) {
    if (!testStackOperations()) {
        printf("Error!");
        return -1;
    }
    return 0;
}
