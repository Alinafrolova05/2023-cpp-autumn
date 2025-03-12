#define _CRT_SECURE_NO_WARNINGS
#define HASH_TABLE_SIZE 100

#include <stdio.h>
#include "test.h"
#include "table.h"

void task(FILE* file) {
    bool errorCode = true;

    HashTable* table = createHashTable(HASH_TABLE_SIZE, &errorCode);
    if (!errorCode) {
        printf("Error!!!");
        return;
    }

    char buffer[100] = "";
    while (fscanf(file, "%99s", buffer) == 1) {
        insertInTable(table, buffer, &errorCode);
        if (!errorCode) {
            printf("Error!!!");
            freeTable(table);
            return;
        }
    }
    fclose(file);

    printTable(table);

    printf("Late Load Factor: %0.2f\n", calcuHashTableFillFactor(table));
    printf("La`te Average List Length: %0.2f\n", calcuLateAverageListLength(table));
    printf("Late Max List Length: %d\n", calcuLateMaxListLength(table));

    freeTable(table);
}

int main(void) {
    if (!test()) {
        fprintf(stderr, "Error!!!\n");
        return -1;
    }
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error!");
        return;
    }
    task(file);
    fclose(file);
    return 0;
}
