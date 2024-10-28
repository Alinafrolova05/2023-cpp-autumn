#include <iostream>
void selectionsort(int* a, int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		int min = j;
		for (int i = j; i < size; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		std::swap(a[j], a[min]);
	}
}
void print(int* a, int size)
{
	std::cout << std::endl;
	std::cout << "Отсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << " ";
	}
}
int main(int argc, char* argv[])
{
	std::cout << "Укажите размер массива: ";
	int size = 0;
	std::cin >> size;
	int* a = new int[size];
	std::cout << "Введите числа, которые будут находиться в массиве: ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}
	selectionsort(a, size);
	print(a, size);
	delete[] a;
	return EXIT_SUCCESS;
}