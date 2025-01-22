#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "operations.h"
#include "stack.h"

int main(void) {

    if (!testStackOperations()) {
        printf("Error!");
        return -1;
    }
    
    return 0;
}
