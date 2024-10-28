#include <iostream>
#include <fstream>

class M
{
public:
	int a = 0;
	int b = 0;
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
		int edges = 0;
		input >> size;
		input >> edges;
		M* list = new M[edges];
		output << size << std::endl;
		for (int i = 0; i < edges; ++i)
		{
			input >> list[i].a;
			input >> list[i].b;
		}
		for (int j = 1; j <= size; ++j)
		{
			int count = 0;
			for (int i = 0; i < edges; ++i)
			{
				if (list[i].a == j )
				{
					count++;
				}
			}
			output << count << " ";
			for (int k = 0; k < edges; ++k)
			{
				if (list[k].a == j)
				{
					output << list[k].b << " ";
				}
			}
			output << std::endl;
		}
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
