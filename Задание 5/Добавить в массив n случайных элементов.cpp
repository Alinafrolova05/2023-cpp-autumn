#include <iostream>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ������ �������: ";
	int size = 0;
	std::cin >> size;
	int* a = (int*)malloc(1000 * sizeof(int));

	// ���������� �������
	std::cout << "������� �����, ������� ����� ���������� � �������" << " : ";
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
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	//���������� n ���������
	
	std::cout << "������� ���������� ���������, ������� �� ������ �������� � ������: ";
	int n = 0;
	std::cin >> n;
	std::cout << "������� ���������, ������� �� ������ ��������: ";
	std::cout << std::endl;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		std::cin >> k;
		*(a + i + size ) = k;
	}

	std::cout << "������, � ������� �������� n ��������� " << ": ";
	for (int i = 0; i < size + n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;



	//������������ ������
	free(a);
	return EXIT_SUCCESS;
}