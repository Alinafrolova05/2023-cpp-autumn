#include <iostream>
#include <fstream>
#include <vector>

struct Matr
{
	int* line = new int[255];
};
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
		int n = 0;
		input >> n;
		Matr* m = new Matr[n];
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				input >> m[i].line[j];
			}
		}
		std::vector<int> numbers2;
		int origins = 0;

		for (int i = 0; i < n; ++i)
		{
			int check = 0;
			for (int j = 0; j < n; ++j)
			{
				if (m[j].line[i] == 1)
				{
					check++;
				}
			}
			if (check == 0)
			{
				origins++;
				numbers2.push_back(i + 1);
			}
		}
		output << origins;
		for (int i = 0; i < origins; ++i)
		{
			output << " " << numbers2[i];
		}
		output << std::endl;

		std::vector<int> numbers1;
		int drains = 0;
		
		for (int i = 0; i < n; ++i)
		{
			int check = 0;
			for (int j = 0; j < n; ++j)
			{
				if (m[i].line[j] == 1)
				{
					check++;
				}
			}
			if (check == 0)
			{
				drains++;
				numbers1.push_back(i + 1);
			}
		}
		output << drains;
		for (int i = 0; i < drains; ++i)
		{
			output << " " << numbers1[i];
		}		
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
