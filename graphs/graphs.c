#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "functions.h"

int main() {
    FILE* file = fopen("text.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }
    else if (!testSort()) {
        perror("Sort doesn't work!");
        fclose(file);
        return -1;
    }

    int n = 0;
    fscanf(file, "%d", &n);
    Graphs* table = (Graphs*)calloc(n, sizeof(Graphs));

    listOf(file, table, n);

    int k = 0;
    fscanf(file, "%d", &k);
    int* capitals = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        fscanf(file, "%d", &capitals[i]);
    }
    fclose(file);

    Graphs* state = (Graphs*)calloc(k, sizeof(Graphs));
    for (int i = 0; i < k; ++i) {
        state[i].number = capitals[i];
        state[i].weight = 0;
        state[i].next = NULL;
    }

    algorithm(table, n, capitals, state, k);
    print(state, k);

    for (int i = 0; i < n; i++) {
        while (&table[i] != NULL) {
            pop(&table[i]);
        }
    }
    for (int i = 0; i < k; i++) {
        while (&state[i] != NULL) {
            pop(&state[i]);
        }
    }

    free(table);
    free(capitals);
    free(state);
    return 0;
}
