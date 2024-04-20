#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Matr
{
public:
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
		int* mas = new int[255];
		int m = 0;
		int num = 0;
		for (int i = 0; !input.eof(); ++i)
		{
			input >> num;
			mas[i] = num;
			m++;
		}
		int n = mas[0];
		Matr* p = new Matr[n];
		int y = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				p[i].line[j] = mas[y];
				y++;
			}
		}

		int min = 5000;
		for (int i = 0; i < n; ++i)
		{
			int max2 = 0;
			for (int j = 0; j < n; ++j)
			{
				int a = 0;
				for (int k = 0; k < n; ++k)
				{      
					if (p[i].line[j] != 0 && p[k].line[j] != 0 && p[k].line[i] != 0)
					{
						a = p[i].line[j] + p[k].line[j] + p[k].line[i];
						if (a < min)
						{
							min = a;
						}
					}
				}
			}
		}
		output << min;


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				p[i].line[j];
			}
		}
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
