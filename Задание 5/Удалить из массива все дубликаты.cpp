#include <iostream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ������ �������: ";
	int size = 0;
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));
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
	//�������� ���������� 
	int r = 0;
	for (int j = 0; j < size; ++j)
	{
		for (int i = j + 1; i < size ; ++i)
		{
			if (*(a + j) == *(a + i ))
			{
				for (int k = i; k < size - 1; k++)
				{
					*(a + k) = *(a + k + 1);
				}
				--size;
				++r;
			}
			else
			{
				continue;
			}
		}
	}
	std::cout << std::endl;

	//����� �������
	std::cout << "���������� ������ ��� ���������� " << ": ";
	for (int i = 0; i <= size - r; ++i)
	{
		std::cout << *(a + i) << " ";
	}


	free(a);

	return EXIT_SUCCESS;

}