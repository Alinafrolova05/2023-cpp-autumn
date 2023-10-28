#include <iostream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int size = 0;
	std::cin >> size;
	int* a = (int *)malloc(1000 * sizeof(int));

	// Заполнение массива
	std::cout << "Введите числа, которые будут находиться в массиве" << " : ";
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}

	//Вывод массива
	std::cout << "Полученный массив " << ": ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	//Чистим память
	free(a);
	return EXIT_SUCCESS;
}
