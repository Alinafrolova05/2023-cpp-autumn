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
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Количество чисел, которые будут добавлены в массив: ";
	int n = 0;
	std::cin >> n;
	std::cout << "Введите числа, которые будут добавлены в массив: ";
	std::cout << std::endl;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		std::cin >> k;
		*(a + i + size ) = k;
	}
	std::cout << "Массив, в который добавили n элементов: ";
	for (int i = 0; i < size + n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;
	free(a);
	return EXIT_SUCCESS;
}