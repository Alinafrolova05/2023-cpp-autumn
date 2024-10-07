#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void swap(int* left, int* right) {
	*left ^= *right;
	*right ^= *left;
	*left ^= *right;
}

void QSort(int* array, int indexStart, int indexFinish) {
	if (indexStart >= indexFinish) {
		return;
	}

	int startValue = indexStart;
	int finish = indexFinish;
	int value = array[indexStart];
	while (startValue + 1 <= finish) {
		if (array[startValue + 1] < value) {
			swap(&array[startValue + 1], &array[startValue]);
			if (startValue + 1 == finish) {
				break;
			}
			startValue++;
		}
		if (array[startValue + 1] >= value) {
			if (startValue + 1 == finish) {
				break;
			}
			swap(&array[startValue + 1], &array[finish]);
			finish--;
		}
	}
	QSort(array, startValue + 1, indexFinish);
	QSort(array, indexStart, startValue);
}

void BubbleSort(int size, int* array) {
	for (int i = 0; i < size; ++i) {
		for (int j = i; j > 0; --j) {
			if (array[j] < array[j - 1]) {
				swap(&array[j], &array[j - 1]);
			}
		}
	}
}

void CountingSort(int size, int* array) {
	int max = 0;
	for (int i = 0; i < size; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	printf("  max = %d  ", max);
	int* anotherArray = (int*)calloc(max, sizeof(int));
	for (int i = 0; i < size; ++i) {
		anotherArray[array[i]]++;
	}
	int k = 0;
	for (int i = 0; i < max; ++i) {
		for (int j = 0; j < anotherArray[i]; ++j) {
			array[k] = i;
			k++;
		}
	}
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

	//SelectionSort(size, array, 0, 1, 1);
	//ShellSort(size, array);
	//BubbleSort(size, array);
	//CountingSort(size, array);
	//QSort(array, 0, size - 1);

	printf("\nSorted array: ");
	for (int i = 0; i < size; ++i) {
		printf(" %d", array[i]);
	}

	return 0;
}
