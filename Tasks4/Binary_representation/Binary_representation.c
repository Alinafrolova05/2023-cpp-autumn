#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "bit.h"

#define BITS 8

int main(void) {
    setlocale(LC_ALL, "Rus");

    int number1 = 0;
    int number2 = 0;

    printf("Введите число1 от -127 до 127: ");
    int result = scanf("%d", &number1);
    if (result != 1 || number1 < -127 || number1 > 127) {
        printf("Ошибка! ");
        return -1;
    }

    printf("Введите число2 от -127 до 127: ");
    result = scanf("%d", &number2);
    if (result != 1 || number2 < -127 || number2 > 127) {
        printf("Ошибка! ");
        return -1;
    }

    int binary1[BITS] = { 0 };
    int binary2[BITS] = { 0 };

    for (int i = 0; i < BITS; i++) {
        binary1[BITS - 1 - i] = (number1 >> i) & 1;
        binary2[BITS - 1 - i] = (number2 >> i) & 1;
    }

    printf("Число %d в двоичном представлении: ", number1);
    printBitArray(binary1);

    printf("Число %d в двоичном представлении: ", number2);
    printBitArray(binary2);

    int sum[BITS] = { 0 };
    addBinary(binary1, binary2, sum);

    printf("Сумма в двоичном представлении: ");
    printBitArray(sum);

    int decimalSum = 0;
    for (int i = 0; i < BITS; i++) {
        decimalSum += sum[BITS - 1 - i] << i;
    }
    printf("Сумма в десятичном представлении: %d\n", decimalSum);

    return 0;
}
