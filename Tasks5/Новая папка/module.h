#ifndef H
typedef struct Element {
    char brace;
    struct Element* next;
}Element;
void push(Element* head2, char brace);
void pop(Element* head2);
void ifBrace(Element* element1, char brace1);
void fillStack(Element* element1, char str[]);

#endif