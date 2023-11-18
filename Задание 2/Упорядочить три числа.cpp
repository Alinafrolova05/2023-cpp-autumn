#include <iostream>
int main(int argc, char* argv []) 
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	// a
	if (a < b && a < c) 
	{
		if (a < b && b < c) 
		{
			std::cout << a << " " << b << " " << c;
		}
	}
	if (a < b && a < c) 
	{
		if (a < c && c < b) 
		{
			std::cout << a << " " << c << " " << b;
		}
	}
	//b
	if (b < a && b < c) 
	{
		if (b < a && a < c) 
		{
			std::cout << b << " " << a << " " << c;
		}
	}
	if (b < a && b < c) 
	{
		if (b < c && c < a) 
		{
			std::cout << b << " " << c << " " << a;
		}
	}
	//c
	if (c < a && c < b) 
	{
		if (c < a && a < b) 
		{
			std::cout << c << " " << a << " " << b;
		}
	}
	if (c < a && c < b) 
	{
		if (c < b && b < a) 
		{
			std::cout << c << " " << b << " " << a;
		}
	}
	// если какие-то из a, b, c равны 
	if (a == b && a < c) 
	{
		std::cout << a << " " << b << " " << c;
	}
	if (a == b && c < a) 
	{
		std::cout << c << " " << a << " " << b;
	}
	if (b == c && a < c) 
	{
		std::cout << a << " " << b << " " << c;
	}
	if (b == c && c < a) 
	{
		std::cout << b << " " << c << " " << a;
	}
	if (a == c && a < b) 
	{
		std::cout << a << " " << c << " " << b;
	}
	if (a == c && b < a) 
	{
		std::cout << b << " " << a << " " << c;
	}
	if (a == b && a == c && b == c) 
	{
		std::cout << a << " " << b << " " << c;
	}
	return EXIT_SUCCESS;
}