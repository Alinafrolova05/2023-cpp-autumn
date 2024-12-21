#include "test.h"
#include "Module.h"
#include <stdbool.h>

bool test(void) {
    int array1[] = { 3, 6, 68, 3, 0 };
    int array2[] = { 3, 6, 68, 88, 0 };
    int count = 0;
    commonElement(5, array2, 88, &count);
    return count <= 1 && commonElement(5, array1, 68, &count) == 3;
}