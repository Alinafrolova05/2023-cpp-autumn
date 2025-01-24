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
    Element* element = calloc(1, sizeof(Element)); // �������� ������ ��� ������ ��������
    if (element == NULL) { // �������� �� �������� ��������� ������
        *errorCode = false; // ������������� ��� ������
        return;
    }

    element->value = value; // ������������� �������� ������ ��������

    // ���� ������ ���� ��� ����� �������� ������ ��� ����� �������� ������� ��������
    if (*head == NULL || (*head)->value >= value) {
        element->next = *head; // ������������� ��������� ������� ��� ������ ��������
        *head = element; // ��������� ��������� �� ������ �������
        return;
    }

    Element* current = *head; // ��������� ��� ��������� �� ������

    // ���� ����� ��� ������� ������ ��������
    while (current->next != NULL && current->next->value < value) {
        current = current->next; // ���������� ��������� �� ��������� �������
    }

    // ��������� ����� ������� � ������
    element->next = current->next; // ������������� ��������� ������� ��� ������ ��������
    current->next = element; // ��������� ����� ������� � ������
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
