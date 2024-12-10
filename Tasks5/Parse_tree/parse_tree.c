#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

int main() {
    printf("Enter the string: ");
    char str[256] = { 0 };
    fgets(str, 256, stdin);

    Stack* numberStack = NULL;
    Stack* operationStack = NULL;

    tree(str, &numberStack, &operationStack);
    Element* root = numberStack->element;
    count(root);

    print(pop(&numberStack));
    printf("\nValue is: %d", root->result);
    return 0;
}
