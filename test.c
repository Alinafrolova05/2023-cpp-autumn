#include <stdbool.h>
#include <stdio.h>
#include "list.h"
#include "table.h"

bool test(void) {
    bool errorCode = true;
    char* array[] = { "apple", "april", "orange", "orange" };

    float* task = NULL;
    solution(array, 4, &errorCode, &task);
    float dutyCycle = task[0];
    float averageListLength = task[1];
    float maxLength = task[2];
    free(task);

    return errorCode && dutyCycle == 0,04 && averageListLength == 0,75 && maxLength == 1;
}
