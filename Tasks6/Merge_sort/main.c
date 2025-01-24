#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "sort.h"

int main(void) {
    if (!testSortByName() || !testSortByNumber()) {
        printf("Error!");
        return -1;
    }
    sort();
    return 0;
}
