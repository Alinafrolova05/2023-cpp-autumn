#include <iostream>
int main(int agc, char* argv []) 
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	cout << a * ((a / b) % (a / b - 1)) + b * ((b / a) % (b / a - 1));
	return EXIT_SUCCESS;
}