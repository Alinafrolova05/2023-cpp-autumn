#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void Dividing(int a, int b) {
    if (b == 0) {
        printf("Error");
    }
    if (a == 0) {
        printf("0");
    } else {
        int i = -abs(a);
        while (1) {
            if (a - b * i >= 0 && a - b * i < abs(b)) {
                printf("Incomplete quotient: %d", i);
                break;
            }
            ++i;
        }
    }
}

int main(void)
{
    const int a = 0;
    const int b = 0;
    printf("Enter the dividend: ");
    int result = scanf("%d", &a);
    printf("Enter the divisor: ");
    result = scanf("%d", &b);
    Dividing(a, b);
    return 0;
}