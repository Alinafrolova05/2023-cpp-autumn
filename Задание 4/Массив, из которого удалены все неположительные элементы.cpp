#include <iostream>
int main(int argc, char**)
{
	int size = 0;
	std::cout << "Укажите размер массива: ";
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));
	std::cout << std::endl;
	std::cout << "Введите числа, которые будут находиться в массиве: ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}
	int k = size;
	for (int i = 0; i < size; i++)
	{
		std::cout << "*(a + i) = " << *(a + i) << " ";
		if (*(a + i) <= 0)
		{
			k--;
			for (int j = i; j < size - 1; j++)
			{
				*(a + j) = *(a + j + 1);
			}
		}
	}
	std::cout << "Полученный массив: ";
	for (int i = 0; i < k; i++)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);
	return EXIT_SUCCESS;
}