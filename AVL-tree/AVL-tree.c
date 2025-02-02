#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "test.h"
#include "solution.h"

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    solution();
    return 0;
}
