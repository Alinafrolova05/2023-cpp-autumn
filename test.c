#include <stdbool.h>
#include <stdio.h>
#include "list.h"
#include "table.h"
#include "countTask.h"

bool test(void) {
    bool errorCode = true;
    char* array[] = { "apple", "april", "orange", "orange" };

    CountTask* task = NULL;
    solution(array, 4, &errorCode, &task);
    int dutyCycle = getArraySize(task);
    int averageListLength = getAverageListLength(task);
    int maxLength = getMaxListLength(task);
    free(task);

    return errorCode && dutyCycle == 4 && averageListLength == 3 && maxLength == 1;
}
