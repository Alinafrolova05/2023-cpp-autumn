#include <iostream>
int main(int argc, char* argv[])
{
	int year = 0;
	std::cin >> year;
	bool mod400 = year % 400 == 0;
	if ((year % 4 == 0 && year % 100 != 0) || mod400) 
	{
		std::cout << "YES";
	}
	else 
	{
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}