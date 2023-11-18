#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cout << "Введите число A: ";
	std::cin >> a;
	std::cout << std::endl;
	int b = 0;
	std::cout << "Введите число B: ";
	std::cin >> b;
	std::cout << std::endl;
	int n = 0;
	std::cout << "Введите число N: ";
	std::cin >> n;
	std::cout << std::endl;

	// a < b
	int c = 0;
	int k = a;
	//
	int k1 = a;
	int b2 = b;
	//
	int x = a;
	int y = b;
	//
	int w1 = a;
	int w2 = b;
	int p = 0;
	if (a < b)
	{
		while (abs(w2 - w1) != n)
		{
			w1 = k;
			w2 = abs(w2 - w1);
			c++;
			if (c >= 100000)
			{
				p++;
				std::cout << "Impossible";
				break;
			}
		}
	}
	bool possible1 = p == 0;
	if (a < b && possible1)
	{
		std::cout << ">A";
		std::cout << std::endl;
		k1 = k;
		std::cout << "A>B";
		std::cout << std::endl;
		b2 = abs(b2 - k1);
		while (abs(y - x) != n)
		{
			std::cout << ">A";
			std::cout << std::endl;
			x = k;
			std::cout << "A>B";
			std::cout << std::endl;
			y = abs(y - x);
		}
	}

	// b < a
	int r = b;
	//
	int r1 = b;
	int t = a;
	//
	int x1 = b;
	int y1 = a;
	//
	int q1 = b;
	int q2 = a;
	int v = 0;
	c = 0;
	if (b < a)
	{
		while (abs(q2 - q1) != n)
		{
			q1 = r;
			q2 = abs(q2 - q1);
			c++;
			if (c >= 100000)
			{
				v++;
				std::cout << "Impossible";
				break;
			}
		}
	}
	bool possible2 = v == 0;
	if (b < a && possible2)
	{
		std::cout << ">B";
		std::cout << std::endl;
		r1 = r;
		std::cout << "B>A";
		std::cout << std::endl;
		t = abs(t - r1);
		while (abs(y1 - x1) != n)
		{
			x1 = r;
			std::cout << ">B";
			std::cout << std::endl;
			y1 = abs(y1 - x1);
			std::cout << "B>A";
			std::cout << std::endl;
		}
	}
	// a = b
	if (a == b)
	{
		if (a == n)
		{
			std::cout << ">A";
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Impossible";
		}
	}

	return EXIT_SUCCESS;
}