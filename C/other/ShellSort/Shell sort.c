#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void swap(int* left, int* right) {
	*left ^= *right;
	*right ^= *left;
	*left ^= *right;
}

void SelectionSort(int size, int* array, int i1, int j1, int condition) {
	for (int i = i1; i < size - 1; i += condition) {
		for (int j = i + j1; array[j] < array[j - condition] && j > condition - 1; j -= condition) {
			swap(&array[j], &array[j - condition]);
		}
	}
}

void ShellSort(int size, int* array) {
	int step = 3;
	int k = 0;
	while (k < size) {
		if (k >= step) {
			k = 0;
			step += step;
			if (step >= size) {
				SelectionSort(size, array, 0, 1, 1);
				break;
			}
		}
		SelectionSort(size + 1, array, step + k, 0, step);
		k++;
	}
}

int main()
{
	int size = 11;
	int* array = (int*)calloc(size, sizeof(int));

	srand(time(NULL));
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 100;
	}

	printf("The resulting array: ");
	for (int i = 0; i < size; ++i) {
		printf(" %d", array[i]);
	}

	ShellSort(size, array);
	
	printf("\nSorted array: ");
	for (int i = 0; i < size; ++i) {
		printf(" %d", array[i]);
	}

	return 0;
}
