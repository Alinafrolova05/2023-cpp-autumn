#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

bool testScanf(int result) {
    return result == 1;
}
bool testInteger(float power, int additionalbool) {
    if (power < 0) {
        power = -power;
    }
    return power != additionalbool;
}

void calculationPowerLog(float number, float *pointernumber, float staticNumber, int additionalbool, int* pointeradditionalbool,  float power) {
    if (power < 0) {
        power = -power;
    }
    for (size_t i = 1; i < power / 2; ++i) {
        number *= staticNumber;
        additionalbool++;
    }
    if ((additionalbool != power / 2) && staticNumber != 0) {
        number *= number;
        number /= staticNumber;
        additionalbool += additionalbool - 1;
        if (additionalbool < power) {
            number *= staticNumber;
        }
    }
    if (additionalbool == power / 2) {
        number *= number;
        additionalbool += additionalbool;
    }
    *pointernumber = number;
    *pointeradditionalbool = additionalbool;
}

void calculationPowerLin(float number, float *pointernumber, float staticNumber, float power, int additionalbool, int *pointeradditionalbool) {
    if (power < 0) {
        power = -power;
	}
    for (size_t i = 1; i < power; ++i) {
        number *= staticNumber;
        additionalbool++;
    }
    *pointernumber = number;
    *pointeradditionalbool = additionalbool;
}

void print(float number, float power) {	
    if (power > 0) {
        printf(" %f ", number);
    }
    else if (power < 0) {
        printf(" %f ", 1 / number);
    }
    else {
        printf(" 1 ");
    }
}

int main()
{
    printf("Enter number: ");
    float number = 0;
    int result = scanf("%f", &number);
    if (!testScanf(result)) {
        printf("Input error!");
        return 0;
    }

    printf("Enter an integer that will be the power: ");
    float power = 0;
    result = scanf("%f", &power);
    if (!testScanf(result)) {
        printf("Input error!");
        return 0;
    }
   
    int additionalbool = 1;
    float staticNumber = number;

    calculationPowerLog(number, &number, staticNumber, additionalbool, &additionalbool,  power);
    //calculationPowerLin(number, &number, staticNumber, power, additionalbool, &additionalbool);

    if (testInteger(power, additionalbool) && power != 0) {
        printf("Input error, power is not an integer!!!\nNumber to the integer part of the power: ");
        if (staticNumber == 0 ) {
            print(number, power);
            return 0;
        } else {
            print(number / staticNumber, power);
            return 0;
        }
    }
     
    printf("\nNumber %f to the power %f: ", staticNumber, power);
    print(number, power);
    return 0;
}
