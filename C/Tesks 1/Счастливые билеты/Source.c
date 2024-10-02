#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int main(int argc, char argv[])
{
	int* mas = (int*)malloc(1000* sizeof(int));
	for (int i = 0; i < 28; ++i)
	{
		mas[i] = 0;
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				mas[i + j + k]++;
			}
		}
	} 
	int count = 0;
	for (int i = 0; i < 28; ++i)
	{
		count += (mas[i])* (mas[i]);
	}
	printf("Количество счастливых билетов равно: %d", count);
	free(mas);
	return 0;
}
