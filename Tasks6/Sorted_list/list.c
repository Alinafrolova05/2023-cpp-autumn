#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include "list.h"

struct List {
    struct Element* front;
    struct Element* back;
};

void scanfChecker(int* add) {
    int result = scanf("%d", add);
    if (result != 1) {
        printf("\nInput wrong!");
        return -1;
    }
}

void pop(Element** head) {
    Element* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void addElement(Element** head, int value, bool* errorCode) {
    Element* element = calloc(1, sizeof(Element)); // Выделяем память для нового элемента
    if (element == NULL) { // Проверка на успешное выделение памяти
        *errorCode = false; // Устанавливаем код ошибки
        return;
    }

    element->value = value; // Устанавливаем значение нового элемента

    // Если список пуст или новое значение меньше или равно значению первого элемента
    if (*head == NULL || (*head)->value >= value) {
        element->next = *head; // Устанавливаем следующий элемент для нового элемента
        *head = element; // Обновляем указатель на первый элемент
        return;
    }

    Element* current = *head; // Указатель для навигации по списку

    // Ищем место для вставки нового элемента
    while (current->next != NULL && current->next->value < value) {
        current = current->next; // Перемещаем указатель на следующий элемент
    }

    // Вставляем новый элемент в список
    element->next = current->next; // Устанавливаем следующий элемент для нового элемента
    current->next = element; // Вставляем новый элемент в список
}

void deleteElement(Element* head, int value) {
    if (head == NULL || head->value < value) {
        return;
    }
    Element* index = head;
    while (head->next->value != value) {
        if (head->next == NULL || head->next->value < value) {
            head = index;
            return;
        }
        head = head->next;
    }
    Element* deleting = head->next;
    head->next = head->next->next;
    free(deleting);
    head = index;
}

void freeList(Element** element) {
    while (*element != NULL) {
        pop(element);
    }
}
