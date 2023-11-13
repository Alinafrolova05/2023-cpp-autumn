#include <iostream>
#include <cmath>


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Укажите размер массива: ";
	int size = 0;
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));
	int* b = (int*)malloc(1000 * sizeof(int));
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
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::endl;
		std::cout << i << ". ";
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	//Поиск номера максимального и минимального элемента
	int start = *a;
	int min = 0;
	for (int i = 0; i < size; ++i)
	{
		if (*(a + i) <= start)
		{
			start = *(a + i);
			min = i;
		}
		else
		{
			continue;
		}
	}

	int max = 0;
	for (int i = 0; i < size; ++i)
	{
		if (*(a + i) >= start)
		{
			start = *(a + i);
			max = i;
		}
		else
		{
			continue;
		}

	}
	std::cout << std::endl;

	//Перестановка минимального и максимального элемента 
	std::swap(*(a + max), *(a + min));
	std::cout << std::endl;

	//Вывод массива
	std::cout << "Полученный массив с учетом перестановки " << ": ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(a + i) << " ";

	}
	std::cout << std::endl;

	//Освобождение массива
	free(a);
	return EXIT_SUCCESS;
}
