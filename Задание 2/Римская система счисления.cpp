#include <iostream>
int main(int argc, char* argv []) 
{
	int x = 0;;
	std::cin >> x;
	if (x == 100) 
	{
		std::cout << "C";
	}
	if (x / 10 == 1) 
	{
		std::cout << "X";
	}
	if (x / 10 == 2) 
	{
		std::cout << "XX";
	}
	if (x / 10 == 3) 
	{
		std::cout << "XXX";
	}
	if (x / 10 == 4) 
	{
		std::cout << "XL";
	}
	if (x / 10 == 5) 
	{
		std::cout << "L";
	}
	if (x / 10 == 6) 
	{
		std::cout << "LX";
	}
	if (x / 10 == 7) 
	{
		std::cout << "LXX";
	}
	if (x / 10 == 8) 
	{
		std::cout << "LXXX";
	}
	if (x / 10 == 9) 
	{
		std::cout << "XC";
	}
	if (x % 10 == 1) 
	{
		std::cout << "I";
	}
	if (x % 10 == 2) 
	{
		std::cout << "II";
	}
	if (x % 10 == 3) 
	{
		std::cout << "III";
	}
	if (x % 10 == 4) 
	{
		std::cout << "IV";
	}
	if (x % 10 == 5) 
	{
		std::cout << "V";
	}
	if (x % 10 == 6) 
	{
		std::cout << "VI";
	}
	if (x % 10 == 7) 
	{
		std::cout << "VII";
	}
	if (x % 10 == 8) 
	{
		std::cout << "VIII";
	}
	if (x % 10 == 9) 
	{
		std::cout << "IX";
	}
	return EXIT_SUCCESS;
}