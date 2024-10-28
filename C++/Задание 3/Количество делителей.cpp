#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			k++;
		}
	}
	std::cout << k;
	return EXIT_SUCCESS;
}