#include <iostream>
int main(int agc, char* argv []) 
{
	int k = 0;
	std::cin >> k;
	cin >> "The next number for the number" >> k >> "is";
	cout << k + 1 << "." << endl;
	cout << "The previous number for the number" << k << "is";
	cout << k - 1 << ".";
	return EXIT_SUCCESS;
}