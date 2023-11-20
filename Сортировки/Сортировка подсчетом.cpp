#include <iostream>
void insertionSort(int* a, int size)
{
    for (int i = 1; i < size; i++) 
    {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k) 
        {
            std::swap(a[j + 1], a[j]);
            j--;
        }
    }
}
void printArray(int* a, int size)
{
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << " ";
    }
}
int main()
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
        a[i] = n;
    }
    insertionSort(a, size);
    printArray(a, size);
    delete[] a;
    return 0;
}