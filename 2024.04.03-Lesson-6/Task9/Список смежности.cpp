#include <iostream>
#include <fstream>

class CGraph
{
public:
	int* line = new int[255];
	~CGraph()
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
		output << size << std::endl;
		CGraph M;
		CGraph* g = new CGraph[size];
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				g[i].line[j] = 0;
			}
		}
		int a = 0;
		for (int i = 0; i < size; ++i)
		{
			input >> a;
			int b = 0;
			for (int j = 0; j < a; ++j)
			{ 
				input >> b;
				g[i].line[b - 1] = 1;
			}
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				output << g[i].line[j] << " ";
			}
			output << std::endl;
		}
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
