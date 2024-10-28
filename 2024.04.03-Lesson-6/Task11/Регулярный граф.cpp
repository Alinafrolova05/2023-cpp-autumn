#include <iostream>
#include <fstream>

struct Matr
{
	int count = 0;
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
		Matr* m = new Matr[size];
		int check = 0;
		for (int i = 0; i < size; i++)
		{
			int a = 0;
			int c = 0;
			for (int j = 0; j < size; j++)
			{
				input >> a;
				if (a == 1)
				{
					c++;
				}
			}
			m[i].count = c;
			if (m[i].count == m[0].count)
			{
				check++;
			}
		}

		if (check == size)
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
