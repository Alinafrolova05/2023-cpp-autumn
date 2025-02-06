#include <stdbool.h>
#include <stdio.h>
#include "table.h"
#include "test.h"

bool test(void) {
    bool errorCode = true;
    Segment* hashTable = NULL;

    insert(&hashTable, "apple", &errorCode);
    insert(&hashTable, "april", &errorCode);
    insert(&hashTable, "orange", &errorCode);
    insert(&hashTable, "orange", &errorCode);

    if (!search(hashTable, "apple")) {
        return false;
    }
    if (!search(hashTable, "orange")) {
        return false;
    }
    if (search(hashTable, "lemon")) {
        return false;
    }

    freeSegments(&hashTable);
    return errorCode == true;
}
