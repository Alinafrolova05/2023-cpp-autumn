#include <iostream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размер массива: ";
	int size = 0;
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));

	// Заполнение массива
	std::cout << "Введите числа, которые будут находиться в массиве" << " : ";
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
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	//Добавление n элементов
	
	std::cout << "Укажите количество элементов, которые Вы хотите добавить в массив: ";
	int n = 0;
	std::cin >> n;
	std::cout << "Введите эелементы, которые Вы хотите добавить: ";
	std::cout << std::endl;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		std::cin >> k;
		*(a + i + size ) = k;
	}

	std::cout << "Массив, в который добавили n элементов " << ": ";
	for (int i = 0; i < size + n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;



	//Освобождение памяти
	free(a);
	return EXIT_SUCCESS;
}