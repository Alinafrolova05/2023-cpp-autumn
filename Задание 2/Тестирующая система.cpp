#include <iostream>
int main(int argc, char* argv[]) 
{
	int a, b;
	std::cin >> a >> b;
	if (a == 1 && b == 1) 
	{
		std::cout << "YES";
	}
	if (a == 1 && b != 1) 
	{
		std::cout << "NO";
	}
	if (a != 1 && b == 1) 
	{
		std::cout << "NO";
	}
	if (a != 1 && b != 1) 
	{
		std::cout << "YES";
	}
	return EXIT_SUCCESS;
}