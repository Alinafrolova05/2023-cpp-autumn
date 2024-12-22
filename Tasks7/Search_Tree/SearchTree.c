#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

int main(void) {
    Node* root = NULL;
    menu(&root); 
    freeTree(root);
    return 0;
}

