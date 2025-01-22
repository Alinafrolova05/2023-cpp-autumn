#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "balance.h"

typedef struct Element {
    char value;
    struct Element* next;
}Element;

void processBraces(char* str, Element** element1, bool* errorCode) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
            if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
                if (*element1 != NULL) {
                    char lastBrace = (*element1)->value;
                    if ((str[i] == ')' && lastBrace == '(') ||
                        (str[i] == '}' && lastBrace == '{') ||
                        (str[i] == ']' && lastBrace == '[')) {
                        pop(element1);
                    }
                    else {
                        push(element1, str[i], errorCode);
                    }
                }
                else {
                    push(element1, str[i], errorCode);
                }
            }
            else {
                push(element1, str[i], errorCode);
            }
        }
    }
}

bool test(void) {
    bool errorCode = true;
    Element* element = NULL;
    char string[] = ")[]";
    char incorrect[] = ")";
    processBraces(string, &element, &errorCode);

    char check[100] = "";
    int i = 0;
    while (element != NULL) {
        check[i] = element->value;
        i++;
        pop(&element);
    }
    return strcmp(incorrect, check) == 0 && errorCode == true;
}
