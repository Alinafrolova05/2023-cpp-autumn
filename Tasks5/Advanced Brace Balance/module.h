#ifndef ADVANCED_BRACE_BALANCE
#pragma once
typedef struct Element {
    char brace;
    struct Element* next;
}Element;
void push(Element** element1, char brace1);
void pop(Element** element1);
#endif