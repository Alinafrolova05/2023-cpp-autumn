#include "module.h"
void push(Element* head2, char brace) {
    Element* element = malloc(sizeof(Element));
    element->brace = brace;
    element->next = head2;
    head2 = element;
}

void pop(Element* head2) {
    Element* tmp = head2;
    head2 = head2->next;
    free(tmp);
}

void ifBrace(Element* element1, char brace1) {
    if (element1->next->brace == brace1) {
        printf("!!!");
        pop(element1);
        pop(element1);
    }
}

void fillStack(Element* element1, char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == '{' || str[i] == "[" || str[i] == ')' || str[i] == '}' || str[i] == ']') {
            printf("\n%c", str[i]);
            push(element1, str[i]);

            if (str[i] == ')') {
                ifBrace(element1, '(');
            }
            if (str[i] == '}') {
                ifBrace(element1, '{');
            }
            if (str[i] == ']') {
                ifBrace(element1, '[');
            }
        }
    }
}