#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element* next;
}Element;

void push(Element** head, int value) {
    Element* element = calloc(1, sizeof(Element));
    element->value = value;
    element->next = *head;
    *head = element;
}

void deleteElement(Element** front) {
    if (*front == NULL || (*front)->next == NULL) {
        return;
    }
    Element* delete = (*front)->next;
    (*front)->next = delete->next;
    free(delete);
}

void stackPart1(Element* list, FILE* file2, const int a) {
    if (list == NULL) {
        return;
    }
    stackPart1(list->next, file2, a);
    if (list->next->value < a) {
        fprintf(file2, " %d", list->value);
        deleteElement(&list);
    }
}

void stackPart2(Element* list, FILE* file2, const int a, const int b) {
    if (list == NULL) {
        return;
    }
    stackPart2(list->next, file2, a, b);
    if (list->next->value > a && list->next->value < b) {
        fprintf(file2, " %d", list->value);
        deleteElement(&list);
    }
}

void stackPart3(Element* list, FILE* file2) {
    if (list == NULL) {
        return;
    }
    stackPart3(list->next, file2);
    fprintf(file2, " %d", list->value);
    deleteElement(&list);
}

bool test() {
    const int a = 4;
    const int b = 50;

    Element* list = NULL;

    FILE* file1 = fopen("f.txt", "r");
    FILE* file2 = fopen("g.txt", "w+");
    if (!file1 || !file2) {
        free(list);
        return false;
    }
    int number = 0;
    while (!feof(file1)) {
        fscanf(file1, "%d", &number);
        push(&list, number);
    }

    stackPart1(list, file2, a);
    stackPart2(list, file2, a, b);
    stackPart3(list, file2);
    int buffer[256] = { 0 };
    int i = 0;
    while (!feof(file2)) {
        int number = 0;
        fscanf(file2, "%d", &number);
        buffer[i] = number;
        i++;
    }
    int array[] = {1, 3, 56, 5, 9, 5, 4, 90, 83};

    for (int j = 0; j < i; ++j) {
        if (buffer[j] != array[j]) {
            fclose(file1);
            fclose(file2);
            free(list);
            return false;
        }
    }
    fclose(file1);
    fclose(file2);
    free(list);
    return true;
}

int main() {
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    return 0;
}