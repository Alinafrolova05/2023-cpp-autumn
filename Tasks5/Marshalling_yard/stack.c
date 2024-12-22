#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void push(Element** head, char value) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value;
    element->next = *head;
    *head = element;
}

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void print(Element* numbers) {
    char str1[20] = { 0 };
    int i = 0;
    printf("\nDifferent form: ");

    while (numbers != NULL) {
        str1[i] = numbers->value;
        Element* tmp = numbers;
        numbers = numbers->next;
        free(tmp);
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", str1[j]);
    }
}

void processInput(char* str, Element** numbers, Element** operations) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(') {
            push(operations, str[i]);
        }
        else if ((str[i] == '*' || str[i] == '/') && (*operations != NULL && ((*operations)->value == '*' || (*operations)->value == '/'))) {
            push(numbers, (*operations)->value);
            pop(operations);
            push(operations, str[i]);
        }
        else if ((str[i] == '*' || str[i] == '/') && (*operations == NULL || ((*operations)->value != '*' && (*operations)->value != '/'))) {
            push(operations, str[i]);
        }
        else if ((str[i] == '+' || str[i] == '-') && (*operations != NULL && (*operations)->value != ')' && (*operations)->value != '(')) {
            push(numbers, (*operations)->value);
            pop(operations);
            push(operations, str[i]);
        }
        else if ((str[i] == '+' || str[i] == '-') && (*operations == NULL || (*operations)->value == ')' || (*operations)->value == '(')) {
            push(operations, str[i]);
        }
        else if (str[i] == ')') {
            while (*operations != NULL && (*operations)->value != '(') {
                push(numbers, (*operations)->value);
                pop(operations);
            }
            pop(operations);
        }
        else {
            push(numbers, str[i]);
        }
    }
}

bool test(void) {
    char str[20] = "(2+2)/9";
    char correct[20] = "22+9/";
    Element* numbers = NULL;
    Element* operations = NULL;

    processInput(str, &numbers, &operations);

    char isCorrect[20] = "";

    int i = 0;
    while (numbers != NULL) {
        isCorrect[i] = numbers->value;
        Element* tmp = numbers;
        numbers = numbers->next;
        free(tmp);
        i++;
    }

    return strcmp(correct, isCorrect) == 0;
}
