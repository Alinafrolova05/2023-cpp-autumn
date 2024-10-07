#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int fibonacciRecursion(int number, int *result) {

    if (number < 0) {
        return 1;
    }
    if (number <= 2) {
        return 0;
    }
    int previous = 0;
    fibonacciRecursion(number - 1, &previous);
    int prePrevious = 0;
    fibonacciRecursion(number - 2, &prePrevious);
    *result = previous + prePrevious;
    return 0;
}

int fibonacciIteration(int number, int fibonacci1, int fibonacci2, int fibonaccimain) {

    for (int i = 0; i < number; ++i) {
        fibonaccimain = fibonacci1 + fibonacci2;
        fibonacci2 = fibonacci1;
        fibonacci1 = fibonaccimain;
    }
    return fibonaccimain;
}


int main()
{
    int result = 0;
    for (int i = 0; i < 10000; ++i) {
        if (fibonacciRecursion(i, &result) != 0) {
            printf("Recursion doesn't work!");
            return 0;
        }
        if (fibonacciIteration(i, 0, 1, 0) < 0) {
            printf("Iteration doesn't work!");
            return 0;
        }
        clock_t start1 = clock();
        fibonacciRecursion(i, &result);
        clock_t end1 = clock();
        double recursion = 1000.0 * (end1 - start1) / CLOCKS_PER_SEC;

        clock_t start2 = clock();
        fibonacciIteration(i, 0, 1, 0);
        clock_t end2 = clock();
        double iteration = 1000.0 * (end2 - start2) / CLOCKS_PER_SEC;

        if (recursion > iteration) {
            printf("From the %dth Fibonacci number, the recursive option is slower than the iterative one.\n", i);
            break;
        }        
    }
    return 0;
}
