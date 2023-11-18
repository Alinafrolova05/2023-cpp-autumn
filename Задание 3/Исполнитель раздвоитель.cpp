#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cout << "Введите число a: ";
	std::cin >> a;
	int b = 0;
	std::cout << "Введите число b: ";
	std::cin >> b;
	while (a != b)
	{
		if ((a % 2 == 0 && (a / 2) < b) || (a % 2 == 1) || (a == (b + 1) && a % 2 == 0))
		{
			std::cout << "-1";
			std::cout << std::endl;
			a--;
		}
		else
		{
			a /= 2;
			std::cout << ":2";
			std::cout << std::endl;
		}

	}

	return EXIT_SUCCESS;
}