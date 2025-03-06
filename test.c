#include <stdbool.h>
#include <stdio.h>
#include "list.h"
#include "table.h"

bool test(void) {
    bool errorCode = true;
    char* array[] = { "apple", "april", "orange", "orange" };

    int* task = NULL;
    solution(array, 4, &errorCode, &task);
    int dutyCycle = task[0];
    int averageListLength = task[1];
    int maxLength = task[2];
    free(task);

    return errorCode && dutyCycle == 4 && averageListLength == 3 && maxLength == 1;
}
