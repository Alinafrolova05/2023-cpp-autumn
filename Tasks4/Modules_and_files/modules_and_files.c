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

    int* array = (int*)calloc(size, sizeof(int));

    printImplementation(array, size, initialize(array, size));

    free(array);
    return 0;
}
