#include <stdio.h>
#include "list.h"

bool test(void) {
    bool errorCode = true;
    Element* element = NULL;

    // ��������� �������� � ������
    addElement(&element, 5, &errorCode);
    addElement(&element, 6, &errorCode);

    int array[] = { 5, 6 };
    int checkArray[2] = { 0 };
    int i = 0;

    // ��������� checkArray ���������� �� ������
    Element* current = element; // ���������� ��������� ��������� ��� ���������
    while (current != NULL) {
        checkArray[i++] = current->value;
        current = current->next;
    }

    // ���������, ��������� �� ������ ��������
    if (sizeof(array) / sizeof(array[0]) != i) {
        return false;
    }

    // ��������� ������� ���������
    for (int j = 0; j < i; ++j) {
        if (array[j] != checkArray[j]) {
            return false;
        }
    }

    // ������� ��������
    deleteElement(&element, 5);
    deleteElement(&element, 6);

    // ���������, ��� ������ ���� � ��� ������ true
    return element == NULL && errorCode == true;
}