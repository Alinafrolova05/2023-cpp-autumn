#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main(int argc, char argv[])
{
	setlocale(LC_ALL, "Rus");
	char str[50];
	fgets(str, 49, stdin);
	puts(str);
	int* mas = (int*)malloc(1000 * sizeof(int));
	for (int i = 0; i <= sizeof(str) + 1; ++i)
	{
		mas[i] = 0;
	}
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == '(')
		{
			mas[i] += 3;
		}
		if (str[i] == ')')
		{
			mas[i] += 2;
		}
	}
	for (int i = 0;i <= sizeof(str) + 1; ++i)
	{
		int k = i + 1;
		if (mas[i] == 3)
		{
			while (k <= sizeof(str) - i)
			{
				if (mas[k] == 2)
				{
					mas[i] = 0;
					mas[k] = 0;
					break;
				}
				k++;
			}
		}
	}
	for (int i = 0; i < 512; ++i)
	{
		if (mas[i] == 3)
		{
			printf(" ( is wrong");
			mas[i] == 0;
			count++;
		}
		if (mas[i] == 2)
		{
			printf(" ) is wrong");
			mas[i] == 0;
			count++;
		}
	}
	if (count == 0)
	{
		printf("\nNothing is wrong");
	}
	free(mas);
	return 0;
}