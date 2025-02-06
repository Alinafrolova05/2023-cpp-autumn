#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include "table.h"
#include "test.h"
#include "list.h"

void solution(void) {
    bool errorCode = true;
    Segment* segment = NULL;

    FILE* file = fopen("text.txt", "r");
    char buffer[100] = "";
    while (fscanf(file, "%99s", buffer) == 1) {
        insert(&segment, buffer, &errorCode);
    }
    fclose(file);

    int size = 0;
    int lengthToCount = 0;
    int max = 0;
    while (segment != NULL) {
        int length = 0;
        if (getValue1(segment) != NULL) {
            Element* current = getValue1(segment);
            while (current != NULL) {
                printf("%s  %d\n", getValue2(current), getValue3(current));
                lengthToCount += getValue3(current);
                current = getValue5(current);
                length++;
            }
        }
        if (length > max) {
            max = length;
        }
        segment = getValue4(segment);
        lengthToCount += length;
        size++;
    }

    printf("\nDuty cycle: 1\n");
    printf("Average list length: %d\n", lengthToCount / size);
    printf("Maximum list length: %d", max);

    freeSegments(&segment);
}

int main(void) {
    if (!test()) {
        fprintf(stderr, "Error!!!\n");
        return -1;
    }

    solution();

    return 0;
}
