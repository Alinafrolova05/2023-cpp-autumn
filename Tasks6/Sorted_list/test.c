#include <stdio.h>
#include "list.h"

bool test(void) {
    bool errorCode = true;
    Element* element = NULL;

    // Добавляем элементы в список
    addElement(&element, 5, &errorCode);
    addElement(&element, 6, &errorCode);

    int array[] = { 5, 6 };
    int checkArray[2] = { 0 };
    int i = 0;

    // Заполняем checkArray значениями из списка
    Element* current = element; // Используем временный указатель для навигации
    while (current != NULL) {
        checkArray[i++] = current->value;
        current = current->next;
    }

    // Проверяем, совпадает ли размер массивов
    if (sizeof(array) / sizeof(array[0]) != i) {
        return false;
    }

    // Проверяем порядок элементов
    for (int j = 0; j < i; ++j) {
        if (array[j] != checkArray[j]) {
            return false;
        }
    }

    // Удаляем элементы
    deleteElement(&element, 5);
    deleteElement(&element, 6);

    // Проверяем, что список пуст и код ошибки true
    return element == NULL && errorCode == true;
}