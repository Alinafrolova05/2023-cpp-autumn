#include <iostream>
int main(int argc,char* argv []) 
{
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> n;
	std::cin >> k;
	std::cin >> m;
	if (n % k != 0) 
	{
		std::cout << ((n / k) + 1) * m;
	}
	else 
	{
		std::cout << (n / k) * m;
	}
	return EXIT_SUCCESS;
}