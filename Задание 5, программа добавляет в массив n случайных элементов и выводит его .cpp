#include <iostream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int size = 0;
	std::cin >> size;
	int* a = (int *)malloc(1000 * sizeof(int));

	// ���������� �������
	std::cout << "������� �����, ������� ����� ���������� � �������" << " : ";
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
		std::cout << *(a + i) << " ";
	}

	//������ ������
	free(a);
	return EXIT_SUCCESS;
}
