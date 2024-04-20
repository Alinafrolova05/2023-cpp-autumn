#include <iostream>
#include <vector>
#include <fstream>
class CGraph
{
public:
	std::vector<int> line;
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
		int edges = 0;
		CGraph* g = new CGraph[size];
		for (int j = 0; j < size; ++j)
		{
			for (int i = 0; i < size; ++i)
			{
				int a = 0;
				input >> a;
				g[j].line.push_back(a);
				if (a == 1)
				{
					edges++;
				}
			}
		}
		output << size << " " << edges << std::endl;
		for (int j = 0; j < size; ++j)
		{
			for (int i = 0; i < size; ++i)
			{
				if (g[j].line[i] == 1)
				{
					output << j + 1 << " " << i + 1 << std::endl;
				}
			}
		}
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
