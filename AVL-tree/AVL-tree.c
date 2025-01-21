#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main(void) {
    Node* root = NULL;

    solution(&root);
    freeTree(&root);

    return 0;
}

