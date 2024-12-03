#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "functions.h"

int main() {
    if (test() != 2) {
        fprintf(stderr, "Does not work!!!\n");
        return -1;
    }
    setlocale(LC_ALL, "Rus");
    Hash_table* hash_table = createTable();

    FILE* file = fopen("text.txt", "r");
    char buffer[256] = { 0 };
    if (file == NULL) {
        fprintf(stderr, "The file does not open!!!\n");
        return -1;
    }
    else {
        while (fscanf(file, "%99s", buffer) == 1) {
            insert(hash_table, buffer);
            printf("%s ", buffer);
        }
    }

    printf("\n\na: %d", search(hash_table, "the"));

    fclose(file);
    freeTable(hash_table);
    return 0;
}
