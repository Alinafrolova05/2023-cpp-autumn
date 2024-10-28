#include <iostream>
#include <fstream>

class CGraph
{
public:
	int a = 0;
	int b = 0;
};
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
		int vertices = 0;
		int edges = 0;
		input >> vertices;
		input >> edges;
		CGraph* g = new CGraph[edges];
		Matr* m = new Matr[vertices];
		for (int i = 0; i < edges; ++i)
		{
			input >> g[i].a;
			input >> g[i].b;
		}


		for (int i = 0; i < vertices; ++i)
		{
			for (int y = 0; y < vertices; ++y)
			{
				m[i].line[y] = 0;
			}
		}

		for (int i = 0; i < vertices; ++i)
		{
			for (int y = 0; y < vertices; ++y)
			{
				for (int j = 0; j < edges; ++j)
				{
					if (g[j].a == i + 1 && g[j].b == y + 1)
					{
						m[i].line[y]++;
					}
				}
			}
		}
		int check = 0;
		for (int i = 0; i < vertices; ++i)
		{
			for (int j = 0; j < vertices; ++j)
			{
				if (((m[i].line[j] == 1 && m[j].line[i] != 0) || (m[i].line[j] == 0 && m[j].line[i] != 1)) && i != j)
				{
					check++;
				}
				std::cout << m[i].line[j] << " ";
			}
			std::cout << std::endl;
		}
		if (check == 0)
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
