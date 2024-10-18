#include <iostream>
#include <fstream>

class Matr
{
public:
	int* line = new int[255];
	~Matr()
	{
		delete[]line;
	}
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
		int size = 0;
		input >> size;
		Matr M;
		Matr* g = new Matr[size];
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				input >> g[i].line[j];
			}
		}

		int checkgraph = 0;
		int checkloops = 0;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (g[i].line[j] != g[j].line[i])
				{
					checkgraph++;
				}
				if (g[i].line[i] != 0)
				{
					checkloops++;
				}
			}
		}
		if (checkgraph > 0 && checkloops == 0)
		{
			output << "YES";
		}
		else
		{
			output << "NO";
		}
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
