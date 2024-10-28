#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int b = 0;
	std::cin >> b;
	int c = 0;
	std::cin >> c;
	int d = 0;
	std::cin >> d;
	int x1 = 0;
	for (int i = -abs(d); i <= abs(d); i++)
	{
		if (i == 0)
		{
			i++;
		}
		if (abs(d) % i == 0)
		{
			if (a * (i * i * i) + b * (i * i) + c * i + d == 0)
			{
				x1 = i;
			}
		}
	}
	std::cout << "Целочисленные корни: ";
	std::cout << std::endl;
	std::cout << "x1 = " << x1;
	a = a;
	b = a * x1 + b;
	c = b * x1 + c;
	int x2 = 0;
	int x3 = 0;
	int discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
	{
		int xx2 = (-b + sqrt(discriminant)) / (2 * a);
		int xx3 = (-b - sqrt(discriminant)) / (2 * a);

		if (xx2 * (2 * a) == -b + sqrt(discriminant))
		{
			x2 = (-b + sqrt(discriminant)) / (2 * a);
			std::cout << std::endl;
			std::cout << "x2 = " << x2;
		}
		if (xx3 * (2 * a) == - b - sqrt(discriminant))
		{
			x3 = (-b - sqrt(discriminant)) / (2 * a);
			std::cout << std::endl;
			std::cout << "x3 = " << x3;
		}
	}
	return EXIT_SUCCESS;
}