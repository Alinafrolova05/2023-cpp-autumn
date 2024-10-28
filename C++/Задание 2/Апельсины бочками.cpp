#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	if (n % 10 == 1 && n % 100 != 11)
	{
		std::cout << n << " bochka";
	}
	if (n % 10 > 1 && n % 10 < 5 && n % 100 != 12 && n % 100 != 13 && n % 100 != 14)
	{
		std::cout << n << " bochki";
	}
	if( n % 10 > 4 && n % 10 <= 9 || n % 10 == 0 && x)
	{
		std::cout << n << " bochek";
	}
	if (n % 100 == 11 || n % 100 == 12 || n % 100 == 13 || n % 100 == 14)
	{
		std::cout << n << " bochek";
	}
	return EXIT_SUCCESS;
}