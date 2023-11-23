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
	moveTower1(amount - 1, point1, point2, temp);
	move(amount, point1, point2);
	moveTower1(amount - 1, point2, point1, temp);
}
void moveTower(int amount, int point1, int point2, int temp)
{
	if (amount == 0)
	{
		return;
	}
	moveTower1(amount - 1, point1, point2, temp);
	move(amount, point1, temp);
	moveTower1(amount - 1, point2, point1, temp);
	move(amount, temp, point2);
	moveTower1(amount - 1, point1, point2, temp);
}
void main()
{
	int amount = 0;
	std::cin >> amount;
	moveTower(amount, 1, 3, 2);
}