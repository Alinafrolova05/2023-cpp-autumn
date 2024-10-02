#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(int argc, char argv[])
{
	int a = 0;
	int b = 0;
	printf("Введите делимое: ");
	scanf_s("%d", &a);
	printf("Введите делитель: ");
	scanf_s("%d", &b);
	for (int i = 0; i >= 0; ++i)
	{
		if (b == 0)
		{
			printf("Ошибка");
			break;
		}
		if (a == 0)
		{
			printf("0");
			break;
		}
		if (b * i > a && a > 0 && b > 0)
		{
			printf("Остаток равен: %d", a - b * (i - 1));
			break;
		}
		if (a > 0 && b < 0 && b * (-i) > a)
		{

			printf("Остаток равен: %d", a + b * (i - 1));
			break;
		}
		if (a < 0 && b > 0 && b * (-i) < a)
		{
			printf("Остаток равен: %d", a + b * i);
			break;
		}
		if (b * i < a && a < 0 && b < 0)
		{
			printf("Остаток равен: %d", a - b * i);
			break;
		}
	}
	return 0;
}