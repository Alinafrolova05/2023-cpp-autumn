#include <iostream>
#include <cmath>


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ������ �������: ";
	int size = 0;
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));
	int* b = (int*)malloc(1000 * sizeof(int));
	//���� �������
	std::cout << "������� �����, ������� ����� ���������� � �������: ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int n = 0;
		std::cin >> n;
		*(a + i) = n;
	}

	//����� �������
	std::cout << "���������� ������ " << ": ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::endl;
		std::cout << i << ". ";
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	//����� ������ ������������� � ������������ ��������
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

	//������������ ������������ � ������������� �������� 
	std::swap(*(a + max), *(a + min));
	std::cout << std::endl;

	//����� �������
	std::cout << "���������� ������ � ������ ������������ " << ": ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << *(a + i) << " ";

	}
	std::cout << std::endl;

	//������������ �������
	free(a);
	return EXIT_SUCCESS;
}
