#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testScanf(int result) { 
    return result == 1;
}
bool testPositive(float size) {
    return size >= 0;
}
bool testInteger(float size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        count++;
    }
    return count == size;
}
bool testSwap(int *left, int *right) {
    return left != right;
}

void swap(int* left, int* right) {
    if (!testSwap(left, right)) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
} 
void sort(int* array, int start, int finish) {
    if (start >= finish) {
        return;
    }
    int value0 = array[start];
    int indexStart = start;
    int indexFinish = finish;
    while (indexStart + 1 <= indexFinish) {
        if (array[indexStart + 1] < value0) {
            swap(&array[indexStart + 1], &array[indexStart]);
            if (indexStart + 1 == indexFinish) {
                break;
            }
            indexStart++;
        }
        else if (array[indexStart + 1] >= value0) {
            if (indexStart + 1 == indexFinish) {
                break;
            }
            swap(&array[indexStart + 1], &array[indexFinish]);
            indexFinish--;
        }
    }
    sort(array, indexStart + 1, finish);
    sort(array, start, indexStart);
}

void search(int* array, int start, int finish, int k, int* count) {
    int middle = (finish - start) / 2;
    if (array[start + middle] == k) {
        *count = 1;
        return;
    }
    if (finish - start <= 1) {
        if (array[start] == k || array[start + 1] == k) {
            *count = 1;
        }
        return;
    }
    if (array[start + middle] > k) {
        search(array, start, start + middle - 1, k, count);
        
    }
    if (array[start + middle] < k) {
        search(array, start + middle + 1, finish, k, count);
    }
}

int main() {
    float size = 0;
    printf("Enter size of the array: ");
    int result = scanf("%f", &size);
    if (!testScanf(result)) {
        printf("Input error!");
        return -1;
    }
    if (!testPositive(size) || !testInteger(size)) {
        printf("Error!!! the number must be a positive integer!");
        return -1;
    }

    printf("Indicate the number of numbers whose presence should be checked in the previous array: ");
    float kSize = 0;
    result = scanf("%f", &kSize);
    if (!testScanf(result)) {
        printf("Input error!");
        return -1;
    }
    if (!testPositive(kSize) || !testInteger(kSize)) {
        printf("Error!!! the number must be a positive integer!");
        return -1;
    }

    int* array = (int*)calloc(size, sizeof(int));
    int* kArray = (int*)calloc(kSize, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
    for (int i = 0; i < kSize; ++i) {
        kArray[i] = rand() % 100;
    }
    printf("The resulting array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    sort(array, 0, size - 1);
    printf("\nSorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\nChecked numbers: ");
    for (int i = 0; i < kSize; ++i) {
        printf("%d ", kArray[i]);
    }

    int counеIdenticalNumbers = 0;
    printf("\nNumbers that are in the first array: ");
    for (int i = 0; i < kSize; ++i) {

        int count = 0;
        search(array, 0, size - 1, kArray[i], &count);
        if (count == 1) {
            counеIdenticalNumbers++;
            printf(" %d", kArray[i]);
        }
    }
    if (counеIdenticalNumbers == 0) {
        printf(" no number belongs to the first array.");
    }
    free(array);
    free(kArray);
    return 0;
}
