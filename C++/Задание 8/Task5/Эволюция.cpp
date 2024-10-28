#include <iostream>
#include <fstream>
//Реализуем алгоритм с помощью списка смежности ребер
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
		int* stream = new int[3];
		for (int i = 0; i < 3; ++i)
		{
			input >> stream[i];
		}
		M list;
		list.a = stream[1];
		list.b = stream[2];

		while (list.a != list.b)
		{
			if (list.a > list.b)
			{
				list.a /= 2;
			}
			else
			{
				list.b /= 2;
			}
		}
		output << list.a;
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
