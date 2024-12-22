#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main(void) {
    if (!test()) {
        printf(stderr, "Doesn't work!!!");
        return -1;
    }
    return 0;
}

