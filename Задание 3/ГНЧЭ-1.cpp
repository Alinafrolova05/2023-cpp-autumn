#include <iostream>
int main() 
{
	int N = 0;
	std::cin >> N;
	std::cout << "1" << " ";
	int number = 2;
	int kolighestvo = 1;
	int kolighestvo_number = 0;
	while ((kolighestvo <= (N - 1)) && kolighestvo_number != number) 
	{
		std::cout << number << " ";
		kolighestvo_number += 1;
		kolighestvo += 1;
		if (kolighestvo_number == number) 
		{
			number += 1;
			kolighestvo_number = 0;
		}
	}
	return EXIT_SUCCESS;
}