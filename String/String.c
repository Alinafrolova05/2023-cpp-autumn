#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int decimalRepresentation(char string[]) {
    int decimalValue = 0;
    int length = strlen(string);

    for (int i = 0; i < length; ++i) {
        decimalValue *= 2; 
        if (string[i] == '1') {
            decimalValue += 1;
        }
        else if (string[i] != '0') {
            printf("Error!\n");
            return -1;
        }
    }
    return decimalValue;
}

bool test() {
    char string[65] = {"1010"};
    return decimalRepresentation(string) == 10;
}

int main() {
    if (!test()) {
        printf("Error!");
        return -1;
    }
    char string[65];
    printf("Enter a binary string: ");
    scanf("%64s", string);

    int decimalValue = decimalRepresentation(string);

    if (decimalValue != -1) {
        printf("Decimal representation: %d\n", decimalValue);
    }
    else {
        printf("Error!");
    }

    return 0;
}
