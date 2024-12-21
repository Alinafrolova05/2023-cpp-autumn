#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdbool.h>
#include <locale.h>
#include "module.h"

int main(void)
{
    setlocale(LC_ALL, "Rus");
    int number1 = 1;
    int number2 = 1;
    
    printf("Введите число1 от -127 до 127: ");
    int result = scanf("%d", &number1);
    if (result != 1 || number1 < -127 || number1 > 127) {
        printf("Ошибка! ");
        return -1;
    }
    printBit(number1);
    
    printf("\nВведите число2 от -127 до 127: ");
    result = scanf("%d", &number2);
    if (result != 1 || number2 < -127 || number2 > 127) {
        printf("Ошибка! ");
        return -1;
    }
    printBit(number2);
    
    int sum = number1 | number2;
    printf("\nСумма в двоичном представлении: ");
    printBit(sum);
    printf("\nСумма в десятичном представлении: %d", sum);

    return 0;
}
