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
	int max = *a;
	for (int i = 0; i < size; ++i)
	{
		if (*(a + i) > max)
		{
			max = *(a + i);
		}
	}
	std::cout << "Максимальный элемент: " << max;
	free(a);
	return EXIT_SUCCESS;
}