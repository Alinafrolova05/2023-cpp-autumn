#include <iostream>
int main(int argc, char* argv[]) 
{
	int n = 0;
	std::cin >> n;
	int a = 0;
	// пятая цифра
	a = n / 60;
	// четвертая цифра
	int b = 0;
	b = (n % 60) / 20;
	// третья цифра
	int c = 0;
	c = ((n % 60) % 20) / 10;
	// вторая цифра
	int d = 0;
	d = (((n % 60) % 20) % 10) / 5;
	// первая цифра
	int e = 0;
	e = ((((n % 60) % 20) % 10));
	std::cout << e << " " << d << " " << c << " " << b << " " << a;
	return EXIT_SUCCESS;
}