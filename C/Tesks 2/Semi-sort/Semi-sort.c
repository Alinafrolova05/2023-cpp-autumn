#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void swap(int *left,int *right) {

    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void sort(int *mas, int size) {
    int value0 = mas[0];
    int indexmas0 = 0;
    int indexfinish = size - 1;
    int i = 1;
    while (i <= indexfinish) {
        if (mas[i] < value0) {
            swap(&mas[i], &mas[indexmas0]);
            indexmas0++;
            i++;
        } else if (mas[i] >= value0) {
            if (i == indexfinish) {
                break;
            }
            swap(&mas[i], &mas[indexfinish]);
            indexfinish--;
        }
    }
}

int main()
{
    int size = 0;
    printf("Specify the number of elements in the array: ");
    int result = scanf("%d", &size);
    int* mas = (int*)calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i) {
        mas[i] = rand() % 100;
    }

    printf("Primordial Array: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", mas[i]);
    }

    sort(mas, size);

    printf("\n");
    printf("The resulting array: ");
    printf("\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", mas[i]);
    }
    free(mas);
    return 0;
}