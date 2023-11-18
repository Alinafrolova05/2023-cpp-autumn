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
	std::cout << "Массив в обратном порядке: ";
	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << *(a + i) << " ";
	}
	return EXIT_SUCCESS;
}