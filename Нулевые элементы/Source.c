#define _CRT_SRCURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
int main(int argc, char* argv[])
{
	int size = 0;
	int count = 0;
	printf("Введите количестов элементов в массиве: ");
	scanf_s("%d", &size);
	int* mas = (int*)malloc(1000 * sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		scanf_s("%d", &n);
		*(mas + i) = n;
		if (n == 0)
		{
			count++;
		}
	}
	printf("\nКоличество нулевых элементов: %d", count);
	free(mas);
	return 0;
}