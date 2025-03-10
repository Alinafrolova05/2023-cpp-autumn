#include "test.h"
#include "balance.h"
#include <stdio.h>

bool test(void) {
    char string[] = ")[]";
    return !processBraces(string);
}
