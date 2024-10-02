#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(int argc, char arrgv[])
{
	int a = 0;
	int b = 0;
	printf("Введите два числа: \n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	if (a > b)
	{
		a += b;
		b = -b;
		b += a;
		a -= b;
	}
	else if (b > a)
	{
		b += a;
		a = -a;
		a += b;
		b -= a;
	}
	printf("%d , %d", a, b);
	return 0;
}