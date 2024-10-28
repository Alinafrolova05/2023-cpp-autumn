#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Matr
{
	int n = 7;
public:
	int color = 0;
	int* line = new int[255];
	void Setn(int n1)
	{
		n = n1;
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
		int* mascolor = new int[255];
		int x = 0;
		for (int i = m - n; i < m; ++i)
		{
			mascolor[x] = mas[i];
			x++;
		}
		Matr* p = new Matr [n];
		int y = 1;
		for (int i = 0; i < n; ++i)
		{
			p[i].color = mascolor[i];
			for (int j = 0; j < n; ++j)
			{
				p[i].line[j] = mas[y];
				y++;
			}
		}

		int* colorline = new int[255];

		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if ((p[i].line[j] == 1) && (p[i].color != p[j].color))
				{
					count++;
				}
			}
		}
		output << count / 2;
		delete[]colorline;
		delete[]mas;
		delete[]mascolor;
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
