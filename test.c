#include "test.h"
#include "balance.h"
#include <stdio.h>

bool test(void) {
    bool errorCode = true;
    char string[] = ")[]";
    char check[10] = "";
    char incorrect[] = ")";

    processBraces(string, &errorCode, check);

    return strcmp(incorrect, check) == 0 && errorCode;
}
