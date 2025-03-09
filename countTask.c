#include "countTask.h"
#include <stdlib.h>

typedef struct CountTask {
    int arraySize;
    int averageListLength;
    int maxListLength;
} CountTask;

CountTask* createCountTask(void) {
    return calloc(1, sizeof(CountTask));
}

int getArraySize(CountTask* task) {
    if (task == NULL) {
        return 0;
    }
    return task->arraySize;
}

int getAverageListLength(CountTask* task) {
    if (task == NULL) {
        return 0;
    }
    return task->averageListLength;
}

int getMaxListLength(CountTask* task) {
    if (task == NULL) {
        return 0;
    }
    return task->maxListLength;
}

void setArraySize(CountTask* task, int value) {
    task->arraySize = value;
}

void setAverageListLength(CountTask* task, int value) {
    task->averageListLength = value;
}

int setMaxListLength(CountTask* task, int value) {
    task->maxListLength = value;
}
