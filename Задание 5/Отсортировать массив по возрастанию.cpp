#include <iostream>
int main(int argc, char* argv[])
{
	std::cout << "Укажите размер массива: ";
	int size = 0;
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));
	std::cout << "Введите числа, которые будут находиться в массиве: ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}
	std::cout << "Полученный массив: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::endl;
		std::cout << i << ". ";
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;
	for (int j = 0; j < size; ++j)
	{
		for (int i = 0; i < size - 1 - j; ++i)
		{
			if (*(a + i) > *(a + i + 1))
			{
				std::swap(*(a + i), *(a + i + 1));
			}
			else
			{
				continue;
			}
		}
	}
	std::cout << "Массив, отсортированный по возрастанию: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);
	return EXIT_SUCCESS;

}