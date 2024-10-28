#include <iostream>
#include <fstream>

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
		int size = 0;
		input >> size;
		for (int i = 0; i < size; ++i)
		{
			int count = 0;
			int a = 0;
			for (int j = 0; j < size; ++j)
			{
				input >> a;
				if (a == 1)
				{
					count++;
				}
			}
			output << count << " ";
		}
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
