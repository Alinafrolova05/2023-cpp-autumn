#include <iostream>
int main(int argc, char* argv[]) 
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	if (a == 0 && b == 0)
	{
		std::cout << "INF";
	}
	else
	{
		if (a == 0)
		{
			std::cout << "NO";
		}
		else
		{
			bool cel = b % a == 0;
			bool CD = c != 0 || d != 0;
			bool cd = c * (-b / a) + d != 0;
			if (cel && CD && cd)
			{
				std::cout << (-1) * (b / a);
			}
			else
			{
				std::cout << "NO";
			}
		}
	}
	return EXIT_SUCCESS;
}