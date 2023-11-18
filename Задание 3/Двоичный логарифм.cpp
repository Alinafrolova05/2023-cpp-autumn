#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	std::cout << "Введите число N: ";
	std::cin >> n;
	int r = 1;
	int k = 0;
	while (r < n)
	{
		r *= 2;
		k++;
	}
	std::cout << "k = " << k - 1;
	return EXIT_SUCCESS;
}