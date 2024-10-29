#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include "module.h"
#include "test.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    FILE* file = fopen("text.txt", "r");
    int size = 10;
    int result = fscanf(file,"%d", &size);
    printf("������ �������: %d\n", size);
    if (!testScanf(result)) {
        printf("������ �����! ");
        return -1;
    }

    int* array = (int*)calloc(size, sizeof(int));
    int maxElement = 0;
    srand(time(NULL));
    printf("������ ��������� ����� �� 0 �� %d:\n", size);
    int checkSizeInteger = 0;
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100; 
        if (array[i] > maxElement) { 
            maxElement = array[i];
        }
        printf("%d ", array[i]);
        checkSizeInteger++;
    }
    if (!test(size, checkSizeInteger)) {
        printf("����� ������ ���� �����������! ");
        return -1;
    }

    int countElement = 0;
    int mostCommonElement = 0;
    commonElement(size, array, maxElement, &countElement, &mostCommonElement);

    if (countElement <= 1) {
        printf("\n� ������� ��� ���������� �����. ");
    }
    else {
        printf("\n����� %d - ����� ������ �������. ", mostCommonElement);
    }
    fclose(file);
    free(array);
	return 0;
}
