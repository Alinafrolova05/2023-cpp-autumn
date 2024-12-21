#include "bit.h"
#include <stdbool.h>

#define BITS 8

void printBitArray(int bitArray[BITS]) {
    for (int i = 0; i < BITS; i++) {
        printf("%d", bitArray[i]);
    }
    printf("\n");
}

void addBinary(int binary1[BITS], int binary2[BITS], int result[BITS]) {
    int carry = 0;
    for (int i = BITS - 1; i >= 0; i--) {
        result[i] = binary1[i] + binary2[i] + carry;
        if (result[i] >= 2) {
            result[i] -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }
}
