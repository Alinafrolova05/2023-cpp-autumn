#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "balance.h"

void push(Element** element1, char brace1) {
    Element* element = calloc(1, sizeof(Element));
    element->brace = brace1;
    element->next = *element1;
    *element1 = element;
}

void pop(Element** element1) {
    Element* tmp = *element1;
    *element1 = (*element1)->next;
    free(tmp);
}

void processBraces(char* str, Element** element1) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
            if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
                if (*element1 != NULL) {
                    char lastBrace = (*element1)->brace;
                    if ((str[i] == ')' && lastBrace == '(') ||
                        (str[i] == '}' && lastBrace == '{') ||
                        (str[i] == ']' && lastBrace == '[')) {
                        pop(element1);
                    }
                    else {
                        push(element1, str[i]);
                    }
                }
                else {
                    push(element1, str[i]);
                }
            }
            else {
                push(element1, str[i]);
            }
        }
    }
}

bool test() {
    Element* element = NULL;
    char string[] = ")[]";
    char incorrect[] = ")";
    processBraces(string, &element);

    char check[100] = "";
    int i = 0;
    while (element != NULL) {
        check[i] = element->brace;
        i++;
        pop(&element);
    }
    return strcmp(incorrect, check) == 0;
}
