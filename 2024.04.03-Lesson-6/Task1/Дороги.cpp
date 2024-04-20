#include <iostream>
#include <string>
#include <fstream>
int main(int argc, char* argv[])
{
	std::ifstream input;
	input.open("INPUT.txt");
	std::ofstream output;
	output.open("OUTPUT.txt");

	if (!input.is_open())
	{
		std::cout << "Файл не открылся :(";
	}
	else
	{

		char str = ' ';
		int count = 0;
		while (!input.eof())
		{
			input >> str;
			if (str == '1')
			{
				count++;
			}
		}
		output << count / 2;
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}