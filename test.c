#include "test.h"
#include "balance.h"
#include <stdio.h>

bool test(void) {
    char string1[] = ")[]";
    if (processBraces(string1)) {
        return false;
    }

    char string2[] = "{(})";
    if (processBraces(string2)) {
        return false;
    }

    char string3[] = "{}[]";
    if (!processBraces(string3)) {
        return false;
    }

    char string4[] = "{[()]}";
    if (!processBraces(string4)) {
        return false;
    }

    char string5[] = "{[()[}";
    if (processBraces(string5)) {
        return false;
    }

    return true;
}
