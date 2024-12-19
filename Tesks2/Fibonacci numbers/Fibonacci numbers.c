#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool testScanf(int result) {
    return result == 1;
}
bool testPositiveNumber(int number) {
    return number >= 0;
}

int fibonacciRecursion(int number, int *result) {
    if (number <= 0 ) {
        return 1;
    }
    if (number <= 2) { 
        *result = 1;
        return 0;
    }
    int previous = 0;
    fibonacciRecursion(number - 1, &previous);
    int prePrevious = 0;
    fibonacciRecursion(number - 2, &prePrevious);
    *result = previous + prePrevious;
    return 0;
}

bool testRecurtion() {
    int result = 0;
    int check1 = fibonacciRecursion(5, &result);
    int check2 = fibonacciRecursion(10, &result);
    int check3 = fibonacciRecursion(-5, &result);
    return check1 == 0 && check2 == 0 && check3 == 1;
}

int fibonacciIteration(int number, int* result) {
    int fibonacci1 = 0;
    int fibonacci2 = 1;
    int fibonaccimain = 0;
    for (int i = 0; i < number; ++i) {
        fibonaccimain = fibonacci1 + fibonacci2;
        fibonacci2 = fibonacci1;
        fibonacci1 = fibonaccimain;
    }
    *result = fibonaccimain;
    if (fibonaccimain <= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

bool testIteration() {
    int result = 0;
    int check1 = fibonacciIteration(5, &result);
    int check2 = fibonacciIteration(-5, &result);
    return check1 == 0 && check2 == 0;
}

void countTime(int i, double* pointer1, double* pointer2) {
    int result = 0;
    clock_t start1 = clock();
    fibonacciRecursion(i, &result);
    clock_t end1 = clock();
    double recursion = 1000.0 * (end1 - start1) / CLOCKS_PER_SEC;
    *pointer1 = recursion;

    clock_t start2 = clock();
    fibonacciIteration(i, &result);
    clock_t end2 = clock();
    double iteration = 1000.0 * (end2 - start2) / CLOCKS_PER_SEC;
    *pointer2 = iteration;
}

int main(void)
{
    int result = 0;
    printf("Enter the fibonacci number you want to know: ");
    int number = 1;
    int resultScanf = scanf("%d", &number);
    if (!testScanf(resultScanf)) {
        printf("Input error!");
        return 0;
    }
    if (!testPositiveNumber(number)) {
        printf("The number must be positive!");
        return 0;
    }
    if (!testRecurtion() || testIteration()) {
        printf("The sequence does not count!");
        return 0;
    }
    
    fibonacciRecursion(number, &result);
    printf("Fibonacci number calculated by recursion: %d ", result);
    fibonacciIteration(number, &result);
    printf("\nFibonacci number calculated iteratively: %d", result);

    for (int i = 1; i < 10000; ++i) {

        double recursion = 0;
        double iteration = 0;

        countTime(i, &recursion, &iteration);

        if (recursion > iteration + 100) {
            printf("\nFrom the %dth Fibonacci number, the recursive option is slower than the iterative one.\n", i);
            break;
        }        
    }

    return 0;
}
