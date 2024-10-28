#include <iostream>
#include <fstream>
#include <vector>

class CGraph
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
		int n = 0;
		input >> n;
		int one = 0;
		int two = 0;
		input >> one;
		input >> two;
		std::vector<int> one1;
		std::vector<int> two2;
		std::vector<int> general;
		int countgeneral = 0;
		CGraph* g = new CGraph[255];

		for (int i = 0; i < n - 1; ++i)
		{
			input >> g[i].a;
			g[i].b = i + 2;
		}
		int countone = 0;
		int counttwo = 0;
		int y = one;
		while (y != 1)
		{
			for (int i = 0; i < n; ++i)
			{
				if (g[i].b == y)
				{
					one1.push_back(y);
					countone++;
					y = g[i].a;
					break;
				}
			}
		}
		int c = two;
		while (c != 1)
		{
			for (int i = 0; i < n; ++i)
			{
				if (g[i].b == c)
				{
					two2.push_back(c);
					counttwo++;
					c = g[i].a;
					break;
				}
			}
		}
		one1.push_back(1);
		two2.push_back(1);
		countone++;
		counttwo++;
        for (int i = 0; i < countone; ++i)
		{
			for (int j = 0; j < counttwo; ++j)
			{
				if (two2[j] == one1[i])
				{
					general.push_back(one1[i]);
					countgeneral++;
				}
			}
		}
		int k = 0;
		for (int i = 0; i < countgeneral; ++i)
		{
			if (general[i] > k)
			{
				k = general[i];
			}
		}
		output << k;
	}
	output.close();
	input.close();
	return EXIT_SUCCESS;
}
