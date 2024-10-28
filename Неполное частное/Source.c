#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool testResult(int result) {
    return result == 1;
}
bool test(int b) {
    return b != 0;
}

void divide(int a, int b, int* quotient) {
    int i = -abs(a);
    while (true) {
        if (a - b * i >= 0 && a - b * i < abs(b)) {
            *quotient = i;
            break;
        }
        ++i;
    }
}

int main(void)
{
    int a = 1;
    int b = 1;
    printf("Enter the dividend: ");
    int result = scanf("%d", &a);
    if (!testResult(result)) {
        printf("Input error!");
    }

    printf("Enter the divisor: ");
    result = scanf("%d", &b);
    if (!testResult(result)) {
        printf("Input error!");
    }

    if (!test(b)) {
        printf("Error! Divisor cannot be zero!");
        return 0;
    }
    if (!test(a)) {
        printf("0");
    }

    int quotient = 1;
    divide(a, b, &quotient);
    printf("Incomplete quotient: %d", quotient);
    return 0;
}
