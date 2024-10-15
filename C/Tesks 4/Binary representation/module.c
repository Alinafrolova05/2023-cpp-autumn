#include "module.h"
#include <stdbool.h>
bool testScanf(int result) {
    return result == 1;
}
void printBit(int n) {
    int bit = 0b10000000;
    for (int i = 0; i < 8; ++i) {
        printf((n & bit) ? "1" : "0");
        bit = bit >> 1;
    }
}