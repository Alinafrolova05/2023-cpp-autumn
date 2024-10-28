#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cout << "Введите число: ";
	std::cin >> n;
	int f0 = 0;
	int f1 = 1;
	int fi = 0;
	int fminus1 = f1 + f0;
	int fminus2 = f1;
	for (int i = 2; i <= n - 1; i++)
	{
		fi = fminus1 + fminus2;
		fminus2 = fminus1;
		fminus1 = fi;
		if (i == n - 1)
		{
			std::cout << n << "-е число Фибоначчи равно: " << fi;
		}
	}
	return EXIT_SUCCESS;
}