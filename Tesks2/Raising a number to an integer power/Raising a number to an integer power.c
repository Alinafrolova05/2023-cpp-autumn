#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int calculatePowerLog(float number, int power) {
    if (power < 0) {
        number = 1 / number;
        power = -power;
    }

    float result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result *= number;
        }
        number *= number;
        power /= 2;
    }
    return result;
}

int calculatePowerLin(float number, int power) {
    if (power < 0) {
        number = 1 / number;
        power = -power;
    }

    float number1 = number;

    for (int i = 1; i < power; ++i) {
        number *= number1;
    }

    return number;
}

bool test(void) {
    return calculatePowerLog(2, 5) == 32 && calculatePowerLin(2, 5) == 32;
}

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    return 0;
}
