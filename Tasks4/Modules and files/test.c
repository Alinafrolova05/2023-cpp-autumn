#include "test.h"
#include <stdbool.h>
bool testScanf(int result) {
    return result == 1;
}
bool test(int size, int checkSizeInteger) {
    return size == checkSizeInteger && size > 0;
}