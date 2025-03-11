#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "inputOutput.h"
#include "numbers.h"
#include <string.h>

void writeInBuffer(FILE* file, List** phoneList) {
    while (!feof(file)) {
        char array[256] = { '\0' };
        if (fgets(array, 256, file) != NULL) {
            Number* element = createNumber();
            char* arrayForName = calloc(256, sizeof(char));
            char* arrayForNumber = calloc(256, sizeof(char));
            int i = 0;
            while (array[i] != '-' && array[i] != '\0') {
                arrayForName[i] = array[i];
                i++;
            }
            i++;
            int j = 0;
            while (array[i] != '\0') {
                arrayForNumber[j] = array[i];
                i++;
                j++;
            }
            setName(element, arrayForName);
            setNumber(element, arrayForNumber);
            push(phoneList, element);
        }
    }
}

void printList(List* node) {
    while (node != NULL) {
        Number* element = getNumberOfList(node);
        printf("Name: %s, Number: %s", getName(element), getNumber(element));
        node = getNextList(node);
    }
}
