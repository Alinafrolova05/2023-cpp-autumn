#include <iostream>

int main(int argc, char* argv[])
{
	int size = 0;
	std::cin >> size;
	int* a = (int *)malloc(1000 * sizeof(int));

	// Заполним массив 
	std::cout << "Введите числа, которые будут находиться в массиве" << " : ";
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}

	//Выведем массив
	std::cout << "Полученный массив " << ": ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	//Очистим память
	free(a);
	return EXIT_SUCCESS;
}
