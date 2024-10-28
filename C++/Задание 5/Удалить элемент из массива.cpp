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
	std::cout << "Введите индекс элемента, который будет удален: ";
	int k = 0;
	std::cin >> k;
	for (int i = 0; i < size; ++i )
	{
		if (i < k)
		{
			*(a + i) = *(a + i);
		}
		if (i > k)
		{
			*(a + i - 1) = *(a + i);
		}
	}
	std::cout << "Полученный массив: ";
	for (int i = 0; i < size - 1 ; ++i)
	{
		std::cout << std::endl;
		std::cout << i << ". ";
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;
	free(a);
	return EXIT_SUCCESS;
}