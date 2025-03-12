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

bool testSolve(void) {
    bool errorCode = true;
    int size = 3;
    int stateCount = 2;

    Table* table = createTable(3, &errorCode);
    if (!errorCode) {
        return false;
    }
    Table* states = createTable(2, &errorCode);
    if (!errorCode) {
        deleteTable(&table, size);
        return false;
    }

    push(getElementInTable(table, 0), 2, 10, &errorCode);
    if (!errorCode) {
        deleteTable(&table, size);
        deleteTable(&states, stateCount);
        return false;
    }
    push(getElementInTable(table, 1), 1, 10, &errorCode);
    if (!errorCode) {
        deleteTable(&table, size);
        deleteTable(&states, stateCount);
        return false;
    }
    push(getElementInTable(table, 0), 3, 5, &errorCode);
    if (!errorCode) {
        deleteTable(&table, size);
        deleteTable(&states, stateCount);
        return false;
    }
    push(getElementInTable(table, 2), 1, 5, &errorCode);
    if (!errorCode) {
        deleteTable(&table, size);
        deleteTable(&states, stateCount);
        return false;
    }

    push(getElementInTable(states, 0), 1, 0, &errorCode);
    if (!errorCode) {
        deleteTable(&table, size);
        deleteTable(&states, stateCount);
        return false;
    }
    push(getElementInTable(states, 1), 2, 0, &errorCode);
    if (!errorCode) {
        deleteTable(&table, size);
        deleteTable(&states, stateCount);
        return false;
    }

    solve(table, states, size, stateCount, &errorCode);
    if (!errorCode) {
        return false;
    }

    deleteTable(&table, size);
    deleteTable(&states, stateCount);
    return true;
}

bool test(void) {
    return testEmptyTables() && testSolve();
}
