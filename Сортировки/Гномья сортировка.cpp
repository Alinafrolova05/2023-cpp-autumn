#include <iostream>
void gnomesort (int* a, int size)
{
	int k = 0;
	while (k < size)
	{
		if (a[k] == 0)
		{
			k++;
		}
		if (a[k] >= a[k - 1])
		{
			k++;
		}
		if (a[k] < a[k - 1])
		{
			std::swap(a[k], a[k - 1]);
			k--;
		}
	}
}
void print(int* a, int size)
{
	std::cout << std::endl;
	std::cout << "Отсортированный массив: ";
	for (int i = 1; i < size + 1; i++)
	{
		std::cout << a[i] << " ";
	}
}
int main(int argc, char* argv[])
{
	std::cout << "Укажите размер массива: ";
	int size = 0;
	std::cin >> size;
	int* a = new int [size];
	std::cout << "Введите числа, которые будут находиться в массиве: ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}
	gnomesort(a, size);
	print(a, size);
	return EXIT_SUCCESS;
}