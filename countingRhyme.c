#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "solution.h"
#include "test.h"

int main(void) {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    Element* element = solution(41);
    printf("The answer: %d  %d \n", getValue(element), getValue(getNext(element)));
    deleteLine(&element);
    return 0;
}
