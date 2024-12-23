#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int count(int array[], int size, int array2[], int* size2) {
    int max = 0;
    *size2 = 0;

    for (int i = 0; i < size; ++i) {
        int count = 0;
        int number = array[i];
        int original_number = number;

        while (number != 0) {
            count += number % 10;
            number /= 10;
        }

        if (count > max) {
            max = count;
            *size2 = 1;
            array2[0] = original_number;
        }
        else if (count == max) {
            array2[*size2] = original_number;
            (*size2)++;
        }
    }

    return max;
}

bool test(void) {
    int array[] = { 1, 5, 78, 3059, 1000 };
    int expected_max = 17;
    int size2 = 0;
    int array2[10] = { 0 };
    int result = count(array, sizeof(array) / sizeof(array[0]), array2, &size2);
    return result == expected_max;
}

void program(void) {
    int array[256] = { 0 };
    int size = 0;

    printf("Enter size: ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > 256) {
        printf("Error!\n");
        return;
    }

    printf("Enter elements of array: ");
    for (int i = 0; i < size; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Error!\n");
            return;
        }
    }

    int array2[256] = { 0 };
    int size2 = 0;

    int max_sum = count(array, size, array2, &size2);

    printf("\nMaximum sum of digits: %d\n", max_sum);
    printf("Numbers with this sum: ");
    for (int i = 0; i < size2; ++i) {
        printf("%d ", array2[i]);
    }
}

int main(void) {

    if (!test()) {
        printf("Error!\n");
    }

    program();

    return 0;
}
