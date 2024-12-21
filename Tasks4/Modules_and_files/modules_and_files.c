#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include "commonElement.h"
#include "test.h"

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    setlocale(LC_ALL, "Rus");
    FILE* file = fopen("text.txt", "r");
    if (!file) {
        printf("Файл не открылся!");
        return -1;
    }

    int size = 0;
    int result = fscanf(file, "%d", &size);
    fclose(file);
    if (result != 1) {
        printf("Ошибка ввода! ");
        return -1;
    }
    printf("Размер массива: %d\n", size);

    srand(time(NULL));
    printf("Массив рандомных чисел от 0 до %d:\n", size);
    int* array = (int*)calloc(size, sizeof(int));
    int max = 0;
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
        if (array[i] > max) {
            max = array[i];
        }
        printf("%d ", array[i]);
    }

    printImplementation(array, size, max);

    free(array);
    return 0;
}
