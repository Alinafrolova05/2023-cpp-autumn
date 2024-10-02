#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main(int argc, char argv[])
{
	int nam = 0;
	printf("Введите целое число: ");
	scanf_s("%d", &nam);
	printf("\nПростые числа, не превоосходящие числа %d: ", nam);
	for (int i = 2; i < nam; ++i)
	{
		int count = 0;
		for (int j = 2; j < i; ++j)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count == 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}