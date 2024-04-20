#include <iostream>
#include <fstream>
//Реализуем алгоритм с помощью списка ребер
//Даннная система из планет и туннелей представляет собой дерево, не имеющее циклов
//Планета называется важной, если она соединена более чем с одной планетой
class M
{
public:
	int planet1 = 0;
	int planet2 = 0;
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
		int number = 0;
		input >> number;
		M* list = new M[number];
		for (int i = 0; i < number - 1; ++i)
		{
			input >> list[i].planet1;
			input >> list[i].planet2;
		}
		int count = 0;
		for (int j = 0; j < number; ++j)
		{
			int y = 0;
			for (int i = 0; i < number - 1; ++i)
			{
				if (list[i].planet1 == j || list[i].planet2 == j)
				{
					y++;
				}
			}
			if (y > 1)
			{
				count++;
			}
		}
		output << count;
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
