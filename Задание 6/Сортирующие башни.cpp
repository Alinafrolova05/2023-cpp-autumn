#include <iostream>
void move(int amount, int point1, int point2)
{
	std::cout << amount << " " << point1 << " " << point2;
	std::cout << std::endl;
}
void moveTower1(int amount, int point1, int point2, int temp)
{
	if (amount == 0)
	{
		return;
	}
	moveTower1(amount - 1, point1, temp, point2);
	move(amount, point1, point2);
	moveTower1(amount - 1, temp, point2, point1);
}
void moveTower2(int amount, int point1, int point2, int temp)
{
	if (amount == 0)
	{
		return;
	}
	moveTower1(amount - 1, point2, temp, point1);
	amount--;
	moveTower1(amount - 1, temp, point2, point1);
}
void moveTower11(int amount, int point1, int point2, int temp)
{
	if (amount == 0)
	{
		return;
	}
	moveTower1(amount - 1, point1, point2, temp);
	move(amount, point1, temp);
	moveTower1(amount - 1, point2, temp, point1);
}
void moveTower22(int amount, int point1, int point2, int temp)
{
	if (amount == 0)
	{
		return;
	}
	moveTower1(amount - 1, temp, point2, point1);
	amount--;
	moveTower1(amount - 1, point2, temp, point1);
}
void main()
{
	int amount = 0;
	std::cin >> amount;
	int a = amount;
	if (a % 2 == 0)
	{
		moveTower1(amount, 1, 3, 2);
		moveTower2(amount, 1, 3, 2);
	}
	moveTower11(amount, 1, 3, 2);
	moveTower22(amount, 1, 3, 2);
}