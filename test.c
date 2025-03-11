#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "table.h"

bool testCreateHashTable() {
    bool errorCode = true;
    HashTable* hashTable = createHashTable(10, &errorCode);
    bool result = (hashTable != NULL && errorCode);
    freeTable(hashTable);
    return result;
}

bool testInsertAndSearch() {
    bool errorCode = true;;
    HashTable* hashTable = createHashTable(10, &errorCode);
    insert(hashTable, "test", &errorCode);
    insert(hashTable, "example", &errorCode);

    Element* element1 = search(hashTable, "test");
    Element* element2 = search(hashTable, "example");
    Element* element3 = search(hashTable, "notfound");

    bool result = (element1 != NULL && strcmp(getKey(element1), "test") == 0 && getCount(element1) == 1) &&
        (element2 != NULL && strcmp(getKey(element2), "example") == 0 && getCount(element2) == 1) &&
        (element3 == NULL);

    freeTable(hashTable);
    return result;
}

bool testInsertDuplicate() {
    bool errorCode = true;
    HashTable* hashTable = createHashTable(10, &errorCode);
    insert(hashTable, "duplicate", &errorCode);
    insert(hashTable, "duplicate", &errorCode);

    Element* element = search(hashTable, "duplicate");
    bool result = (element != NULL && getCount(element) == 2);

    freeTable(hashTable);
    return result;
}

bool test(void) {
    return testCreateHashTable() && testInsertAndSearch() && testInsertDuplicate();
}
