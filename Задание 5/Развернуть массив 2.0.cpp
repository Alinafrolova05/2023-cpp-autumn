#include <iostream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Укажите размер массива: ";
	int size = 0;
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));
	//Ввод массива
	std::cout << "Введите числа, которые будут находиться в массиве: ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}

	//Вывод массива
	std::cout << "Полученный массив " << ": ";
	for (int i = size - 1; i >= 0; --i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	//Освобождение массива
	free(a);
	return EXIT_SUCCESS;
}


