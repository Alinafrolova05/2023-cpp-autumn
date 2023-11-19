#include <iostream>
int main(int agc, char* argv []) 
{
	int v = 0;
	int t = 0;;
	int a = (v * t - 1) / 109;
	cin >> v >> t;
	cout << v * t / 109 - a;
	return EXIT_SUCCESS;
}