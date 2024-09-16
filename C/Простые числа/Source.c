#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void SimpleNumbers(int number) {
    for (int i = 2; i < number; ++i) {
        int count = 0;
        for (int j = 2; j * j < number; ++j) {
            if (i % j == 0 && i != j) {
                count++;
            }
        }
        if (count == 0) {
            printf(" %d, ", i);
        }
    }
}

int main(void) {
    int number = 0;
    printf("Enter prime numbers: ");
    int result = scanf("%d", &number);
    printf("\nPrime numbers not exceeding numbers %d: ", number);
    SimpleNumbers(number);	
}