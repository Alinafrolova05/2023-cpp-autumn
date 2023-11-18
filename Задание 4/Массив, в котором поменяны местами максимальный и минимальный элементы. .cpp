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
	int start = *a ;
	int max = 0;
	for (int i = 0; i < size; ++i)
	{
		if (*(a + i) > start)
		{
			start = *(a + i);
			max = i;
		}
	}
	int min = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (*(a + i) < start)
		{
			start = *(a + i);
			min = i;
		}
	}
	std::swap(*(a + max), *(a + min));
	std::cout << " Массив, в котором поменяны местами максимальный и минимальный элементы: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	return EXIT_SUCCESS;
}