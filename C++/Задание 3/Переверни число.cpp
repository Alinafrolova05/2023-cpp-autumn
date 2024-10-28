#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	std::cout << n % 10;
	while (n / 10 > 0)
	{
		n /= 10;
		std::cout << n % 10;
	}
	return EXIT_SUCCESS;
}