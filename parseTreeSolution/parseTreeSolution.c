#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "test.h"

int main(void) {
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("File doesn't open!");
        return -1;
    }
    char str[256] = "";
    if (!(fgets(str, sizeof(str), file) != NULL)) {
        printf("Error in file!");
        return -1;
    }
    fclose(file);
    bool errorCode = true;

    Tree* parseTree = tree(str, &errorCode);
    if (!errorCode) {
        printf("Error!");
        freeTree(&parseTree);
        return -1;
    }

    printf("Result: %d\n", countResult(str, &errorCode));
    if (!errorCode) {
        printf("Error!");
        freeTree(&parseTree);
        return -1;
    }

    printf("Tree: ");
    printTree(parseTree);

    freeTree(&parseTree);
    return 0;
}
