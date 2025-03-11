#define _CRT_SECURE_NO_WARNINGS
#define HASH_TABLE_SIZE 100

#include <stdio.h>
#include "test.h"
#include "table.h"

void task(void) {
    bool errorCode = true;

    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error!");
        return;
    }

    HashTable* table = NULL;
    table = createHashTable(HASH_TABLE_SIZE, &errorCode);
    if (!errorCode) {
        printf("Error!!!");
        return -1;
    }

    char buffer[100] = "";
    while (fscanf(file, "%99s", buffer) == 1) {
        if ((float)getElementCountTable(table) / getSizeTable(table) > 0.7) {
            resizeHashTable(&table, &errorCode);
            if (!errorCode) {
                printf("Error!!!");
                freeTable(table);
                return -1;
            }
        }
        insert(table, buffer, &errorCode);
        if (!errorCode) {
            printf("Error!!!");
            freeTable(table);
            return -1;
        }
    }
    fclose(file);

    printTable(table);

    printf("Late Load Factor: %0.2f\n", calculateLoadFactor(table));
    printf("La`te Average List Length: %0.2f\n", calculateAverageListLength(table));
    printf("Late Max List Length: %d\n", calculateMaxListLength(table));

    freeTable(table);
}

int main(void) {
    if (!test()) {
        fprintf(stderr, "Error!!!\n");
        return -1;
    }
    task();
    return 0;
}
