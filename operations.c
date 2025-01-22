#include "operations.h"
#include <stdbool.h>
#include <malloc.h>

typedef struct Element {
    int value;
    struct Element* next;
} Element;

void performOperation(Element* element, char str, int* answer, bool* errorCode) {
    if (str == '+') {
        element->next->value += element->value;
    }
    if (str == '-') {
        element->next->value -= element->value;
    }
    if (str == '/') {
        if (element->value == 0) {
            *errorCode = false;
            return;
        }
        element->next->value /= element->value;
    }
    if (str == '*') {
        element->next->value *= element->value;
    }
    *answer = element->next->value;
}

void processNumbers(Element* element, char str[], int* answer, bool* errorCode) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            performOperation(element, str[i], answer, errorCode);
            pop(&element);
        }
        else {
            int number = (int)(str[i]) - '0';
            push(&element, number, errorCode);
        }
    }
}

bool testStackOperations(void) {
    bool errorCode = true;
    int answer = 0;
    Element* element = NULL;
    char str[20] = "96-12+*";
    processNumbers(element, str, &answer, &errorCode);
    return answer == 9 && errorCode == true;
}
