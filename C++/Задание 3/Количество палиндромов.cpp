#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cout << "Введите число: ";
	std::cin >> n;
	int p = 0;
	for (int i = 0; i <= n; i++)
	{
		int k = n - i;
		//Количество разрядов в числе 
		int w = k;
		int t2 = 1;
		while (w / 10 > 0)
		{
			t2 *= 10;
			w /= 10;
		}
		//Перевернем число
		int r = 0;
		int c = k;
		while (c / 10 > 0)
		{
			r += (c % 10) * t2;
			t2 /= 10;
			c /= 10;
		}
		if (c < 10)
		{
			r += c;
		}
		//Количество палиндромов
		if (k == r)
		{
			p++;
		}
	}
	std::cout << "Количество палиндромов: " << p - 1;
	return EXIT_SUCCESS;
}