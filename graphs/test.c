#include "test.h"
#include "solution.h"
#include "stack.h"
#include <stdio.h>

bool testEmptyTables(void) {
    bool errorCode = true;
    Table* table = createTable(7, &errorCode);
    Table* states = createTable(3, &errorCode);
    solve(table, states, 7, 3, &errorCode);
    deleteTable(&table, 7);
    deleteTable(&states, 3);
    return errorCode;
}

bool test(void) {
    return testEmptyTables();
}
