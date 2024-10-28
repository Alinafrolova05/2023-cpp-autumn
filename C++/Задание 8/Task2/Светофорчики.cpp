#include <iostream>
#include <string>
#include <fstream>
#include <vector>
int main(int argc, char* argv[])
{
	std::ifstream input;
	input.open("INPUT.txt");
	std::ofstream output;
	output.open("OUTPUT.txt");

	if (!input.is_open() || !output.is_open())
	{
		std::cout << "Файл не открылся :(";
	}
	else
	{
		int str = ' ';
		int m = 0;
		int mas[255] = { 0 };
		for (int i = 0; !input.eof(); ++i)
		{
			input >> str;
			int a = str;
			mas[i] = a;
			m++;
		}
		int res[255] = { 0 };
		for (int i = 1; i <= mas[0]; ++i)
		{
			int count = 0;
			for (int j = 2; j < m; ++j)
			{
				if (mas[j] == i)
				{
					count++;
				}
			}
			res[i - 1] = count;
		}
		for (int i = 0; i < mas[0]; ++i)
		{
			output << res[i] << " ";
		}
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}