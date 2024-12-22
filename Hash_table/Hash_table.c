#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "table.h"

int main(void) {
    if (!test()) {
        fprintf(stderr, "Error!!!\n");
        return -1;
    }
    return 0;
}
